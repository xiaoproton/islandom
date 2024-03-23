#include "ansi.h"
inherit OBJECT;

void create()
{
    set("name", "Food");
    set("long","Food that can be eaten ("+GRN+"eat"+NOR+") to increase your Nutrition.\n"
                +"Or, it can be fed ("+GRN+"feed"+NOR+") to others.\n");
    set("unit", " ");
}
