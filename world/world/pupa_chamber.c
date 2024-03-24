// pupa_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed pupa = __DIR__ "item/pupa";
    mixed food = __DIR__ "item/food";

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
        food:1,
    ]));
    setup();
}

void init()
{
    add_action(function(string arg) {
            object me = this_player();
            write(sprintf("Total Number of NPC Ants born with players help: %d .\n",COLONY_D->get_new_ant_total()));
            write(sprintf("We still need %d more new NPC Ants to conquer this remote island.\n",(10000-COLONY_D->get_new_ant_total())));
            write("---------------------secret of reaching the goal-------------------------\n");
            write("-- 1. find some food to 'feed queen' ar Queens Chamber until she produces more eggs.\n");
            write("-- 2. 'take egg' and move to Egg Chamber and 'drop egg' before keep 'nurse egg' there. \n");
            write("-- 3. when egg turns into larva, move them to Larva Chamber to 'feed larva'.\n");
            write("-- 4. you may need more food now for both you and larva, wander around map for food, even outside of colony.\n");
            write("-- 5. 'feed larva' until it turns into pupa, when you can move it to Pupa Chamber.\n");
            write("-- 6. if you run out of food or are killed outside, Resting and Healing place is the place to be.\n");
            write("-- 7. keep 'nurse pupa' so you can make a new npc ant born! CONGRATS!\n");
            write("-- 8. you may have higher power now, which allows you to fight outside to get more food.\n");
            write("-- 9. keep helping more npc ants born until you feel bored.\n");
            write("-- 10.ask more friends to join and you can hace fun by helping them. \n");
            return 1;
        }, ({"goal", "quest"}));

}
