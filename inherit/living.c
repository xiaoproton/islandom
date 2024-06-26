// 生物对象公共方法
inherit OBJECT;
inherit VERB;

#define CMD_PATH "/cmds/cmd/"
#define ADMIN_PATH "/cmds/admin/"
//#define DEMO_PATH "/cmds/demo/"
#define EFUN_PATH "/cmds/efun/"
//#define TEST_PATH "/cmds/test/"
#include "ansi.h"

int is_living() { return 1; }

void set_living(string id)
{
    enable_commands();
    if (id)
    {
        set_living_name(id);
        seteuid(id);
    }
    add_action("command_hook", "", 1);
}

// NPC消息界面 catch_tell()
// void catch_tell(string msg)
// {
//     debug_message(this_object() + msg);
// }

// 生物执行指令接口
int command(string cmd)
{
    return efun::command(cmd);
}

string colourString()
{
    string colour= query("colour") || "b";
    if(colour=="b")
        return BLU;
    if(colour=="y")
        return YEL;
    if(colour=="p")
        return MAG;
    if(colour=="g")
        return GRN;
    if(colour=="r")
        return RED;
}

string appearance()
{

    int size = to_int(query("size") || "1");
    if(size<=2)
        return "tiny " ;
    if(size>2 && size<=4)
        return "small " ;
    if(size>4 && size<=6)
        return "medium " ;
    if(size>6 && size<=8)
        return "large " ;
    if(size>8 && size<=10)
        return "huge " ;
    if(size>10)
        return "giantic ";

}


nomask int command_hook(string arg)
{
    string verb, cmd, test, efun_cmd, demo, admincmd;
    object me, cmd_ob;

    verb = query_verb();
    cmd = CMD_PATH + verb;
    admincmd = ADMIN_PATH + verb;
    //test = TEST_PATH + verb;
    efun_cmd = EFUN_PATH + verb;
    //demo = DEMO_PATH + verb;
    me = this_object();
    //debug_message(sprintf("me %O ",me));
    //debug_message("me->geteuid(): "+me->geteuid());
    //debug_message("me->short(): "+me->short());
    //debug_message("me->shortfilename(): "+me->shortfilename());
    if ((verb = trim(verb)) == "")
        return 0;

    if (!arg && (objectp(environment()) && environment()->query("exits/" + verb)))
    {
        me->command("go " + verb);
    }
    else if (cmd_ob = load_object(cmd) || cmd_ob = load_object(efun_cmd)) // || cmd_ob = load_object(test)  || cmd_ob = load_object(demo))
    {
        return (int)cmd_ob->main(me, arg);
    }
    else if ((me->short()=="Admin(admin)" || me->geteuid()=="Admin(root)" || me->geteuid()=="Admin(syoleen)") && cmd_ob = load_object(admincmd) )
    {
        return (int)cmd_ob->main(me, arg);
    }
    else
    {
        mixed err = parse_sentence(arg ? verb + " " + arg : verb, 0);
        if (intp(err))
        {
            switch (err)
            {
            case 1: // verb 匹配成功
                return 1;
            default:
                return 0;
            }
        }
        return notify_fail(err);
    }

    return 1;
}
