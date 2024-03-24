inherit COMBAT;
inherit LIVING;

varargs void create(int i, int power)
{
    mixed info;
    int i;
    ::create();
    i = random(8)+7;
    info = MONSTER_D->info(i);
    set_living(info[0]);
    set("name", info[1]);
    set("size",info[3]);
    set("power", info[2]+ random(i+1));
    set("unit", " ");
    set("colour", "r");
    if (clonep())
    {
        set("hp", 80+random(20));
        set_heart_beat(2);
    }
}

int can_be_pickedup(int pwr)
{
    return 0;
}

void init()
{
    object me = this_player();

    if (interactive(me) && me->can_fight())
    {
        object ob = query_shadowing(this_object()) || this_object();
        ob->fight(me);
    }
}

object shadowto(object ob)
{
    set_living(geteuid(ob));
    return shadow(ob, 1);
}
