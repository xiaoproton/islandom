// egg_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    set("short", "Egg Chamber");
    set("long", @LONG
    Eggs are growing here. When eggs turn into half lavae,
    they need to be moved to lavae chamber to grow further.
LONG );
    set("exits", ([
        "north":__DIR__ "worker_ant_hall",
    ]));
}

void init()
{


}
