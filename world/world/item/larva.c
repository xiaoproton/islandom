#include "ansi.h"
inherit OBJECT;

void create()
{
    set("name", "Ant Larva");
    set("long","A worm-like young ant that needs to be fed ("+GRN+"feed"+NOR+") in Larva Chamber to grow. \n"
                +" Then it will turn into a Pupa,\n"
                +" which then needs to be moved ("+GRN+"take"+NOR+" and "+GRN+"drop"+NOR+")  to Pupa Chamber.\n"
        );
    set("unit", " ");
}

int can_be_pickedup(int pwr)
{
    object env;
    env = environment(this_object());
    if(env && env->shortfilename()=="larva_chamber")
    {
        return 0;
    }
    return 1;
}
