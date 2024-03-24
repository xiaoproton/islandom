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
    int choice;
    string envname;
    if(random(50)<1)
    {
        choice = random(3);
        envname = environment(this_object())->shortfilename();
        //debug_message("envname "+envname);
        if(envname=="worker_ant_hall")
        {
            if(choice==0)
            {
                say("[NPC Ant]: Eggs, Larvae, Pupae... They need to be in right chambers.\n");
            }
            if(choice==1)
            {
                say("[NPC Ant]: We may go outside if we want to get more food for the colony.\n");
            }
            if(choice==2)
            {
                say("[NPC Ant]: Moving eggs and feeding larvae make us stronger!\n");
            }
        }
        if(envname=="entrance_hall")
        {
            if(choice==0)
            {
                say("[NPC Ant]: Be aware! Monsters may be wandering outside.\n");
            }
            if(choice==1)
            {
                say("[NPC Ant]: Knowing your power level is important.\n");
            }
            if(choice==2)
            {
                say("[NPC Ant]: Good luck! Happy hunting!\n");
            }
        }

    }
}
