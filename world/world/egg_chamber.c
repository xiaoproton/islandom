// egg_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    set("short", "Egg Chamber");
    set("long", @LONG
    Eggs are being incubated. When eggs turn into lavae,
    they need to be moved to lavae chamber within 1 hour.
LONG );
    set("exits", ([
        "north":__DIR__ "worker_ant_hall",
    ]));
}

void init()
{


}
