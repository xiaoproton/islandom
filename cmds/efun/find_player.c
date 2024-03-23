#include <ansi.h>

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        return notify_fail(HIY "Command format: find_player name\n" NOR);
    }
    if (ob = find_player(arg))
        write(HIG + arg + " => " + file_name(ob) + "\n" NOR);
    else
        write(HIR "Couldn't find a play with name " + arg + " .\n" NOR);
    return 1;
}
