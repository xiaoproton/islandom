inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("rival");
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
        set_heart_beat(2);
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
    if(random(30)<1)
    {
        choice = random(4);
        envname = environment(this_object())->shortfilename();
        //debug_message("envname "+envname);
        if(envname=="worker_ant_hall")
        {
            if(choice==0)
            {
                say("[Newbie Tips]: Eggs, Larvae, Pupae... They need to be in right chambers.\n");
            }
            if(choice==1)
            {
                say("[Newbie Tips]: Typing 'look' allows you to see what exits you can go before type 'n', 's' etc. accordingly.\n");
            }
            if(choice==2)
            {
                say("[Newbie Tips]: Typing 'take food' allows you to get them before typing 'eat'.\n");
            }
            if(choice==3)
            {
                say("[Newbie Tips]: Try to type 'help' to see how to play.\n");
            }
        }
        if(envname=="entrance_hall")
        {
            if(choice==0)
            {
                say("[Newbie Tips]: Be aware! Enemies may be wandering outside.\n");
            }
            if(choice==1)
            {
                say("[Newbie Tips]: Typing 'score' and 'i' to know yourself better.\n");
            }
            if(choice==2)
            {
                say("[Newbie Tips]: Type 'take food' when you see food on floor.\n");
            }
            if(choice==3)
            {
                say("[Newbie Tips]: When enemies die, they turn into food.\n");
            }
        }
        if(envname=="egg_chamber")
        {
            if(choice==0)
            {
                say("[Newbie Tips]: Typing 'nurse egg' may make you stronger while benefiting the colony.\n");
            }
            if(choice==1)
            {
                say("[Newbie Tips]: Typing 'score' and 'i' to know yourself better.\n");
            }
            if(choice==2)
            {
                say("[Newbie Tips]: Type 'take food' when you see food on floor.\n");
            }
            if(choice==3)
            {
                say("[Newbie Tips]: Typing 'take larva' allows you carry it.\n");
            }
        }

    }
}
