#include <ansi.h>

int main(object me, string arg)
{
    if (!arg)
        arg = "...。";

    arg = HIC + arg + NOR + "\n";

    write("You said: " + arg);
    say(HIY + me->query("name") + "(" + geteuid(me) + ") said: " NOR + arg);

    return 1;
}
