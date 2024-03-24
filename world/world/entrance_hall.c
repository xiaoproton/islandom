// entrance_hall.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed food = __DIR__ "item/food";
    set("short", "Entrance Hall");
    set("long", @LONG
    The big hall is for all ants to mobilize while there is an important event or potential invasion.
LONG );
    set("exits", ([
        "northest":__DIR__ "the_fork",
        "up":__DIR__ "main_entrance",
    ]));
    set("objects", ([
        food:1,
    ]));
    setup();
}

void init()
{


}
