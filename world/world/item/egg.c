#include "ansi.h"
inherit OBJECT;

void create()
{
    set("name", "Ant Egg");
    set("long","An ant egg that needs to be taken care of ("+GRN+"nurse"+NOR+") in Egg Chamber to grow. \n"
                +" Then it will turn into a larva,\n"
                +" which then needs to be moved ("+GRN+"take"+NOR+" and "+GRN+"drop"+NOR+")  to Larva Chamber.\n"
        );
    set("unit", " ");
}

int can_be_pickedup(int pwr)
{
    object env;
    env = environment(this_object());
    if(env && env->shortfilename()=="egg_chamber")
    {
        return 0;
    }
    return 1;
}
