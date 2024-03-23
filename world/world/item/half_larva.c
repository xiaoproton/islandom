#include "ansi.h"
inherit OBJECT;

void create()
{
    set("name", "Incubating Egg");
    set("long","An ant egg that needs to be taken care of ("+GRN+"nurse"+NOR+") in Egg Chamber to grow. \n"
                +" Then it will turn into a half-larva,\n"
                +" which then needs to be moved to Larva Chamber,\n"
        );
    set("unit", " ");
}

int can_be_pickedup(int pwr)
{
    return 0;
}
