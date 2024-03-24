// the_fork.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed npc = __DIR__ "npc/npc_ant";
    set("short", "Main Entrance");
    set("long", @LONG
    This is the main entrance and exit of the whole colony.
    It is almost at ground level and to the outside of dangerous world, the island.
    Ocean wave may be heard if you listen (type 'listen') properly (with MudLet client, instead of just browser).
LONG );
    set("exits", ([
        "down":__DIR__ "entrnace_hall",
    ]));
    set("objects", ([
        npc:1,
    ]));
    setup();
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
