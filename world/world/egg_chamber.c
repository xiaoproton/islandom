// egg_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed egg = __DIR__ "item/egg";
    mixed npc = __DIR__ "npc/npc_ant";
    mixed food = __DIR__ "item/food";

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
        npc:1,
        food:1,
    ]));
    setup();
}

void init()
{


}
