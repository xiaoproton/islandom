// 0,0,0.c
#include "ansi.h"
inherit DBASE;

string look_shiban();

void create()
{
    set("short", "Worker Ant Hall");
    set("long", @LONG
    Your pheromone tells you this underground space is called Worker Ant Hall,
    which is part of the Queen Islandom underground ant colony.
    A few worker ants are busy walking in and out for the goal;
    raise more ants to conquer this island, then conquer the Earth.
    A small rock is in the middle of the hall.
LONG );
    set("exits", ([
        "north":__DIR__ "0,1,0",
        "south":__DIR__ "0,-1,0",
    ]));
    set("items", ([
        "small rock" : (: look_shiban :),
    ]));
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

string look_shiban()
{
    object me = this_player();
    return YEL+"A small rock. \nThe pheronmone on it tells you, the north is Queens Chamber,\n and the south is Egg Chamber.\n"+NOR;
}
