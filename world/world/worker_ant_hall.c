// worker_ant_hall.c
#include "ansi.h"
//inherit DBASE;
inherit ROOM;

string look_rock();

void create()
{
    mixed food = __DIR__ "item/food";

    set("short", "Worker Ant Hall");
    set("long", @LONG
    Your pheromone tells you this underground space is called Worker Ant Hall,
    which is part of the Queen Islandom underground ant colony.
    A few worker ants are busy walking in and out for the goal;
    raise more ants to conquer this island, then conquer the Earth.
    A small rock (look rock) is in the middle of the hall.
LONG );
    set("exits", ([
        "north":__DIR__ "queens_chamber",
        "south":__DIR__ "egg_chamber",
    ]));
    set("items", ([
        "rock" : (: look_rock :),
    ]));

    load_object(food)->move_object(this_object());;
    set("objects", ([
        food:1,
    ]));
    setup();
}

void init()
{

    add_action(function(string arg) {
        object me = this_player();
        write("You are lstening...");
        me->msp_oob("!!MUSIC(ocean-waves.mp3 L=1 V=100 U=http://islandom.space/storage/)");
        return 1;
        //return me->move("/world/area");
    }, ({"listen", "hear"}));

}

string look_rock()
{
    object me = this_player();
    return YEL+"A small rock. \nThe pheronmone on it tells you, the north is Queens Chamber,\n"
                +" and the south is Egg Chamber.\n"+NOR;
}
