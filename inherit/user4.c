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
    write(sprintf("[命 %s/%s 食 %s/%s 欲 %s/%s]",
                    RED + query("hp") + NOR, HIG + "100" + NOR,
                    BLU + query("food") + NOR, HIG + "100" + NOR,
                    YEL + query("desire") + NOR, HIG + "100" + NOR
                  )
          );
}
