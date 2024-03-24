// egg_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed egg = __DIR__ "item/egg";

    set("short", "Egg Chamber");
    set("long", @LONG
    Eggs, as tiny as white dots, are growing here with some care (type 'nurse'). When eggs turn into larvae,
    they need to be moved (type 'take' and 'drop') to Lavra Chamber to grow further.
LONG );
    set("exits", ([
        "north":__DIR__ "worker_ant_hall",
    ]));

    set("objects", ([
        egg:1,
        egg:1,
    ]));
    setup();
}

void init()
{


}
