inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("npc_ant");
    set("name", "NPC Ant");
    set("unit", " ");
    if (clonep())
    {
        int power = random(20) + 1;
        set("power", power);
        set("hp", 100);
        set("food", random(20)+80);
        set("size",random(3));
        set("power", random(10));
        set("unit", " ");
        set("colour", "g");
        set_heart_beat(1);
    }
}

int can_be_pickedup(int pwr)
{
    return 0;
}

void heart_beat()
{
    if(random(20)<1)
    {
        say("[NPC Ant]: working harder...\n");
    }
    if(random(10)<1)
    {
        object fd = clone_object(__DIR__ "../item/food") ;
        fd->move_object(environment(this_object()));
    }
}
