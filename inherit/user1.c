/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-03-31 15:04:35
 * @LastEditTime: 2022-05-11 15:13:34
 * @LastEditors: 雪风
 * @Description: 自定义 user 对象
 *  https://bbs.mud.ren
 */
#include <ansi.h>
inherit LIVING;

varargs void create(string arg)
{
    if (clonep())
    {
        ::create();
        set_living(arg);

        move_object(START_ROOM);
    }
    else
    {
        // 自动加载VERB指令
        map(get_dir("/verbs/*.c"), function(string file) {
                return "/verbs/" + file;
        })->load();
    }
}

void consume(int level) //smallest task, consumption level = 1, normal task consumption level = 10, biggest task 20
{
    int food, desire,spirit;
    this_object()->query("gender");
    food = to_int(this_object()->query("food"));
    desire = to_int(this_object()->query("desire"));
    spirit = to_int(this_object()->query("spirit"));

    //consume
    food = food - level;

    //recover
    food = food + to_int(level * log2(spirit));
    desire = desire + to_int(0.5 * level * log2(spirit));

    //
    if(food<0)
        food = 0;
    if(desire>100)
        desire = 100;
    if(food>100)
        food = 100;

}

int command(string cmd)
{
    debug_message(ctime() + " " + file_name(this_object()) + " command " + cmd);
    if(cmd[0..2]=="go ")
    {
        consume(1);
    }
    if(cmd[0..4]=="learn")
    {
        consume(2);
    }
    if(cmd[0..4]=="fight")
    {
        consume(8);
    }
    return ::command(cmd); //calling living->command?
}

void net_dead()
{
    say(HIR "玩家(" + geteuid() + ")离开了游戏。\n" NOR);
    destruct();
}
