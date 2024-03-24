#include "ansi.h"

inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("queen");
    set("name", "Queen Islandom");
    set("unit", " ");
    set("power", 152);
    set("hp", 100);
    set("food", random(20)+80);
    set("size",5);
    set("colour", "g");
    set_heart_beat(1);
}

int can_be_pickedup(int pwr)
{
    return 0;
}

void heart_beat()
{
    int choice;
    if(random(50)<1)
    {
        choice = random(3);
        if(choice==0)
        {
            say("[Queen Islandom]: Food helps us to produce more eggs, more ants.\n");
        }
        if(choice==1)
        {
            say("[Queen Islandom]: Hey, Worker Ant, Well done!\n"
                    +" Remember to type "+GRN+"sc"+NOR+" and "+GRN+"i"+NOR+" to monitor your status and inventory.\n ");
        }
        if(choice==2)
        {
            say("[Queen Islandom]: The more power you have, the more things you can carry.\n");
        }
    }


}
