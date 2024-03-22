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


void net_dead()
{
    say(HIR "Ant " + geteuid() + " returns to reality.\n" NOR);
    destruct();
}
