/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-03-31 15:20:12
 * @LastEditTime: 2022-03-31 15:20:12
 * @LastEditors: 雪风
 * @Description: 通用游戏环境设置接口，通过reset()自动加载物品对象到房间
 *  https://bbs.mud.ren
 */
inherit CLEAN_UP;
inherit DBASE;

// void create(){}

object make_inventory(string file)
{
    object ob;

    if(!objectp(ob = new(file)))
        return 0;
    ob->move(this_object());
    return ob;
}

// driver自动定期呼叫此apply
void reset()
{
    /**
     * ob_list:需要加载的对象map列表
     * ob:加载后的对象map列表
     */
    mapping ob_list, ob;
    string file;
    int amount;

    debug_message(sprintf("reset called for %O",this_object()));

    if (!mapp(ob_list = query("objects")))
        return;

    if (!mapp(ob = query_temp("objects")))
        ob = ([]);

    foreach(file, amount in ob_list)
    {
        debug_message(sprintf("foreach %O",ob_list));
        if (amount == 1)
        {
            if(!objectp(ob[file]))
                ob[file] = make_inventory(file);
        }
        else
        {
            if (!arrayp(ob[file]) || (sizeof(ob[file]) != amount))
                ob[file] = allocate(amount);
            for(int i = 0; i < amount; i++)
            {
                if(!objectp(ob[file][i]))
                    ob[file][i] = make_inventory(file);
            }
        }
    }
    // 缓存对象列表
    set_temp("objects", ob);
}

void setup()
{
    reset();
}

// 移除一个出口
void removeExit(string dir)
{
    mapping exits = query("exits");
    if (mapp(exits) && exits[dir])
        map_delete(exits, dir);
}

// 移除随机出口
void removeRandomExit()
{
    mapping exits = query("exits");
    if (mapp(exits) && sizeof(exits) > 1)
    {
        removeExit(element_of(keys(exits)));
    }
}

// 增加一个出口
void addExit(string dir, string dest)
{
    mapping exits = query("exits");
    if (!mapp(exits))
        exits = ([]);
    if (!exits[dir])
        exits[dir] = dest;
}


string lastpathname()
{
    string allpath;
    string *parts ;
    string lastpath;
    allpath= file_name();
    if(parts = explode(allpath,"/"))
    {
        return parts[sizeof(parts) - 1];
    }
    return allpath;
}

string shortfilename()
{
    string lastpath;
    string *parts;
    lastpath = lastpathname();
    if(parts = explode(lastpath,"#"))
    {
        return parts[0];
    }
    return lastpath;
}


// 对象简称
string short()
{
    return sprintf("%s(%s)", query("short")||"???", shortfilename());

}

mixed myPresent(string arg)
{
    mixed ret;
    mixed ob_list;
    mixed obj;
    int num;
    string shortname;
    //debug_message(sprintf("myPresent arg %s", arg));
    ret = present(arg, this_object());
    if(ret)
        return ret;

    ob_list=this_object()->query("objects");
    //debug_message(sprintf("myPresent ob_list %O", ob_list));

    if(ob_list && sizeof(ob_list)>0)
    {
        foreach( obj,num in ob_list)
        {
            shortname = obj->shortfilename();
        // debug_message(sprintf("myPresent shortname %s",shortname));
            if(shortname==arg)
            {
                //debug_message(sprintf("myPresent return %O",obj));
                return load_object(obj);
            }
        }
    }


    return 0;
}
