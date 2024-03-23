#include <ansi.h>

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        return notify_fail(HIY "Command syntax: find_living name\n" NOR);
    }
    if (ob = find_living(arg))
        write(HIG + arg + " => " + file_name(ob) + "\n" NOR);
    else
        write(HIR "Couldn't find a creature with name " + arg + ".\n" NOR);
    return 1;
}
