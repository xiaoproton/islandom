#include "ansi.h"
inherit OBJECT;

void create()
{
    set("name", "Ant Pupa");
    set("long","This cocoon-like pupa does not move itself.\n"
                +" it needs to be taken care of ("+GRN+"nurse"+NOR+") in Pupa Chamber to grow. \n"
                +" Then it will turn into a new NPC Ant,\n"
                +" which is our ultimate goal of the whole colony, including the Queen.\n"
        );
    set("unit", " ");
}

int can_be_pickedup(int pwr)
{
    object env;
    env = environment(this_object());
    if(env && env->shortfilename()=="pupa_chamber")
    {
        return 0;
    }
    return 1;
}
