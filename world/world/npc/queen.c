#include "ansi.h"

inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("queen");
    set("name", "Queen Islandom");
    set("unit", " ");
    set("power", 4096);
    set("hp", 100);
    set("food", random(20)+80);
    set("size",7);
    set("colour", "g");
    set_heart_beat(1);
}

int can_be_pickedup(int pwr)
{
    return 0;
}

void heart_beat()
{

    if(random(50)<1)
    {
        if(random(2)<1)
        {
            say("[Queen Islandom]: Help us to produce more eggs, more ants.\n");
        }
        else
        {
            say("[Queen Islandom]: Hey, Worker Ant, Well done!\n"
                    +" Remember to type "+GRN+"sc"+NOR+" and "+GRN+"i"+NOR+" to monitor your status and inventory.\n ");
        }
    }


}
