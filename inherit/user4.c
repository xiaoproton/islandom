// user4.c
#include <ansi.h>

inherit __DIR__ "user3";
inherit __DIR__ "combat"; // 战斗模块

varargs void create(string arg)
{
    ::create(arg);
    if (clonep())
    {

        //initial value
        set("size", 1);
        set("hp", 90+random(10));
        set("food", 90+random(10));
        set("power", random(5));
        set("unit", " ");
        set("exp", 0);
        set_heart_beat(2);
    }
}

void write_prompt()
{
    if (to_int(query("food"))<=30 )
    {
        write (YEL + "You are feeling your empty stomach." + NOR);
    }
}
