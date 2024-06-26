// larva_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed larva = __DIR__ "item/larva";
    mixed food = __DIR__ "item/food";

    set("short", "Larva Chamber");
    set("long", @LONG
    Lots of worm-like larvae are growing here with some food (type 'feed'). When larvae turn into pupae,
    they need to be moved ('take' and 'drop') to Pupae Chamber to grow further.
LONG );
    set("exits", ([
        "west":__DIR__ "worker_ant_hall",
    ]));

    set("objects", ([
        larva:1,
        larva:1,
        food:1,
    ]));
    setup();
}

void init()
{


}
