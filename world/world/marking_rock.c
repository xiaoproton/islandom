// marking_rock.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed insect = __DIR__ "npc/insect";

    set("short", "Marking Rock");
    set("long", @LONG
    This is outside of the underground colony.
    The special rock indicates it is very close to the Main Entrance.
    It is very bright here. It looks like some food can be found here, as well as enemies.
    This is an area full of both risks and opportunities.
LONG );
    set("exits", ([
        "south":__DIR__ "main_entrance",
    ]));
    set("objects", ([
        insect:1,
    ]));
    setup();
}

void init()
{

}
