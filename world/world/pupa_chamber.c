// pupa_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed pupa = __DIR__ "item/pupa";
    set("short", "Pupa Chamber");
    set("long", @LONG
    Lots of cacoon-like pupae are growing here if being nursed ('nurse') properly.
    When they turn into young adult, we are one-step closer to our Goal about number of NPC ants.
LONG );
    set("exits", ([
        "north":__DIR__ "the_fork",
    ]));
    set("objects", ([
        pupa:1,
        pupa:1,
    ]));
    setup();
}

void init()
{


}
