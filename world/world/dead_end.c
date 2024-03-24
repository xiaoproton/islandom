// dead_end.c
//inherit DBASE;
inherit ROOM;


void create()
{

    set("short", "Dead End");
    set("long", @LONG
    Literally, this is Dead End, the end place for being dead.
    When ants feeling they are reaching the end of their short life, they come to here.
    Their bodies will be properly dealt with here.
    So that their bodies would not cause any troubles or deceases to the whole colony.
LONG );
    set("exits", ([
        "northeast":__DIR__ "the_fork",
    ]));
}

void init()
{


}
