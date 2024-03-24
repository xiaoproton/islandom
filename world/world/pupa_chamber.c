// pupa_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed pupa = __DIR__ "item/pupa";
    set("short", "Pupa Chamber");
    set("long", @LONG
    Lots of cacoon-like pupae are growing here if being nursed ('nurse') properly.
    When they turn into young adult, we are one-step closer
    to our Goal (type 'goal' to check) about number of NPC ants.
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
 add_action(function(string arg) {
        object me = this_player();
        write(sprintf("Total Number of NPC Ants born with players help: %d .\n"),COLONY_D->get_new_ant_total());
        write(sprintf("We still need %d new NPC Ants to conquer this island.\n"),(10000-COLONY_D->get_new_ant_total()));
        return 1;
    }, ({"goal", "quest"}));

}
