// queens_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed queen = __DIR__ "npc/queen";
    mixed egg = __DIR__ "item/egg";
    mixed food = __DIR__ "item/food";

    set("short", "Queens Chamber");
    set("long", @LONG
    A big chamber for Queen Ant Islandom to live.
    She is more than ten times of your size,
    carrying gene from far-far-away home planet.
    She continues needing food (type 'feed') to produce those eggs.
    Eggs need to be moved (type 'take') the Egg Chamber for good tempareture to incubate.
LONG );
    set("exits", ([
        "south":__DIR__ "worker_ant_hall",
    ]));

    //load_object(queen)->move_object(this_object());
    set("objects", ([
        queen:1,
        egg:1,
        food:1,
    ]));
    setup();
}

void init()
{


}
