#include "ansi.h"

inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("queen");
    set("name", "Queen Islandom");
    set("unit", " ");
    set("power", 126);
    set("hp", 100);
    set("food", random(20)+80);
    set("size",5);
    set("colour", "g");
    set_heart_beat(2);
}

int can_be_pickedup(int pwr)
{
    return 0;
}

void heart_beat()
{
    int choice;
    if(random(30)<1)
    {
        choice = random(4);
        if(choice==0)
        {
            say("[Newbie Tips]: Typing 'take egg' and 'drop egg' allows you to move eggs.\n");
        }
        if(choice==1)
        {
            say("[Newbie Tips]: Typing 'feed queen' may make you become stronger.\n ");
        }
        if(choice==2)
        {
            say("[Newbie Tips]: The more power you have, the more things you can carry.\n");
        }
        if(choice==3)
        {
            say(sprintf("[Newbie Tips]: We have achieved %d new NPC ants born.\n",COLONY_D->get_new_ant_total()));
        }
    }


}
