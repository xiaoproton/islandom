inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("npc");
    set("name", " Ant ");
    set("unit", "");
    if (clonep())
    {
        int power = random(20) + 1;
        set("power", power);
        set("hp", 100);
        set("food", random(20)+80);
        set("size",random(3));
        set("power", random(10));
        set("unit", "");
        set("colour", random(3) ? (random(3) ? "b" : "y") : "p");
        set_heart_beat(1);
    }
}
