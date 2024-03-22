// 0,0,1.c
inherit DBASE;


void create()
{
    mixed npc = __DIR__ "npc/npc";
    object result;

    set("short", "Queens Chamber");
    set("long", @LONG
    A big chamber for Queen Ant Islandom to live.
    She is more than ten times of your size,
    carrying gene from far-far-away home planet.
    She continues needing food to produce those eggs.
    Eggs need to be moved the Egg Chamber for good tempareture to incubate.
LONG );
    set("exits", ([
        "south":__DIR__ "0,0,0",
    ]));

    result=load_object(npc);
    debug_message(sprintf("load npc %d"), objectp(result));
    set("objects", ([
        result:1,
    ]));
}

void init()
{


}
