// marking_rock.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed animal = __DIR__ "npc/animal";

    set("short", "Sandy Beach");
    set("long", @LONG
    A place full of sands and rocks and sea views.
    But it feels very DANGEROUS.
LONG );
    set("exits", ([
        "north":__DIR__ "marking_twig",
    ]));
    set("objects", ([
        animal:1,
    ]));
    setup();
}

void init()
{

}
