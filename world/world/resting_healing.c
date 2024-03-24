// resting_healing.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed food = __DIR__ "item/food";
    set("short", "Resting and Healing");
    set("long", @LONG
    If you are sick or hurt, you may feel recovering faster here
    while costing less food than other places.
LONG );
    set("exits", ([
        "southeast":__DIR__ "the_fork",
    ]));
    set("objects", ([
        food:1,
    ]));
    setup();
}

void init()
{


}
