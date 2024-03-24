// worker_ant_hall.c
#include "ansi.h"
//inherit DBASE;
inherit ROOM;

string look_rock();

void create()
{
    mixed npc = __DIR__ "npc/npc_ant";
    mixed food = __DIR__ "item/food";

    set("short", "Worker Ant Hall");
    set("long", @LONG
    Your pheromone tells you this underground space is called Worker Ant Hall,
    which is part of the Queen Islandom underground ant colony.
    A few worker ants are busy walking in and out for the goal;
    raise more ants to conquer this island, then conquer the Earth.
    A small rock (try to type 'look rock') is in the middle of the hall.
LONG );
    set("exits", ([
        "north":__DIR__ "queens_chamber",
        "south":__DIR__ "egg_chamber",
        "east":__DIR__ "larva_chamber",
        "west":__DIR__ "the_fork",
    ]));
    set("items", ([
        "rock" : (: look_rock :),
    ]));

    //load_object(npc)->move_object(this_object());
    //load_object(food)->move_object(this_object());;
    set("objects", ([
        npc:1,
        food:1,
    ]));
    setup();
}

void init()
{

}

string look_rock()
{
    object me = this_player();
    return YEL+"A small rock. \nThe pheronmone on it tells you, the north is Queens Chamber.\n"
                +"Also, this reminds you that you can try to look almost everything.\n"+NOR;
}
