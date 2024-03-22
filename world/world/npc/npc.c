inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("npc");
    set("name", " Worker Ant ");
    set("unit", "");
    if (clonep())
    {
        int power = random(20) + 1;
        set("power", power);
        set("hp", 100);
        set("food", random(20)+80);
        set("def", 3 * lv + random(30));
        set("agi", 2 * lv + random(20));
        set("gender", random(3) ? (random(3) ? "b" : "y") : "p");
        set_heart_beat(1);
    }
}
