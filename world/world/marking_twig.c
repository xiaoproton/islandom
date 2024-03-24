// marking_rock.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed food = __DIR__ "item/food";

    set("short", "Marking Twig");
    set("long", @LONG
    This is outside of the underground colony.
    The special twig indicates it is very close to the Main Entrance.
    It is very bright here. It looks like some food can be found here, as well as enemies.
    This is an area full of both risks and opportunities.
LONG );
    set("exits", ([
        "north":__DIR__ "main_entrance",
    ]));
    set("objects", ([
        food:1,
        food:1,
        food:1,
    ]));
    setup();
}

void init()
{

}
