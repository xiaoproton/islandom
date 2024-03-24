// the_fork.c
//inherit DBASE;
inherit ROOM;


void create()
{

    set("short", "The Fork");
    set("long", @LONG
    This is a fork-shaped path inside the underground colony, leadind to different places.
LONG );
    set("exits", ([
        "east":__DIR__ "worker_ant_hall",
        "northwest":__DIR__ "resting_healing",
        "southwest":__DIR__ "dead_end",
        "south":__DIR__ "pupa_chamber",
        "north":__DIR__ "entrance_hall",
    ]));
}

void init()
{


}
