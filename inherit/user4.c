// user4.c
#include <ansi.h>

inherit __DIR__ "user3";
inherit __DIR__ "combat"; // 战斗模块

varargs void create(string arg)
{
    ::create(arg);
    if (clonep())
    {
        //spirit
        //hp,food,desire  //max always 100
        //power,tech,glamour
        int spirit;
        if(query("gender")=="男")
        {
            spirit = 0;
        }else
        {
            spirit = 1 + random(2);
        }
        //initial value
        set("spirit",spirit);
        set("hp", 90+random(10));
        set("food", 90+random(10));
        set("desire", spirit*5+random(10));
        set("power", spirit*7+random(10));
        set("tech", random(10));
        set("glamour", spirit*2+random(10));

        set_heart_beat(1);
    }
}

void write_prompt()
{
    /*
    write(sprintf("[命 %s/%s 食 %s/%s 欲 %s/%s]\n",
                    HIG + query("hp") + NOR, WHT + "100" + NOR,
                    HIG + query("food") + NOR, WHT + "100" + NOR,
                    HIG + query("desire") + NOR, WHT + "100" + NOR
                  )
          );
          */
    if (to_int(me->query("desire"))>=60 )
    {
        return MAG "你面色绯红, 呼吸加重, 是不是该做点什么了?" NOR;
    }
    if (to_int(me->query("food"))<=40 )
    {
        return YEL "你肚子咕咕叫, 是不是该吃点什么了?" NOR;
    }
}
