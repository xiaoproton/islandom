// the_fork.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed food = __DIR__ "item/food";

    set("short", "The Fork");
    set("long", @LONG
    This is a fork-shaped path inside the underground colony, leadind to different places.
LONG );
    set("exits", ([
        "east":__DIR__ "worker_ant_hall",
        "northwest":__DIR__ "resting_healing",
        "west":__DIR__ "dead_end",
        "south":__DIR__ "pupa_chamber",
        "southwest":__DIR__ "entrance_hall",
    ]));
     set("objects", ([
        food:1,
        food:1,
    ]));
    setup();
}

void init()
{


}
