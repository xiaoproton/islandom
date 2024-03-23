inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("queen");
    set("name", "Queen Islandom");
    set("unit", " ");
    set("power", 4096);
    set("hp", 100);
    set("food", random(20)+80);
    set("size",7);
    set("colour", "g");
    set_heart_beat(1);
}

int can_be_pickedup(int pwr)
{
    return 0;
}

void heart_beat()
{
    msg("emote","more eggs, more ants...");
}
