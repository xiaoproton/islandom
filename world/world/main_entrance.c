// main_entrance.c
//inherit DBASE;
inherit ROOM;


void create()
{

    set("short", "Main Entrance");
    set("long", @LONG
    This is the main entrance and exit of the whole colony.
    It is at ground level and close to the DANGEROUS outside world, the island.
    Ocean wave may be heard if you listen (type 'listen') properly (with MudLet client, instead of just browser).
LONG );
    set("exits", ([
        "down":__DIR__ "entrance_hall",
        "north":__DIR__ "marking_rock",
        "south":__DIR__ "marking_twig",
        "west":__DIR__ "marking_grass",
        "east":__DIR__ "marking_crack",
    ]));
}

void init()
{
    add_action(function(string arg) {
        object me = this_player();
        write("You are listening...");
        me->msp_oob("!!MUSIC(ocean-waves.mp3 L=1 V=100 U=http://islandom.space/storage/)");
        return 1;
        //return me->move("/world/area");
    }, ({"listen", "wave"}));

}
