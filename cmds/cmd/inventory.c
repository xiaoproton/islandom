// inventory.c
#include <ansi.h>

int main(object me, string arg)
{
    string str;
    string cl;

    cl = me->colourString();
    str = sprintf(YEL+"----------- Ant "+NOR+cl+"%s 's Inventory"+NOR+YEL+" -----------\n"+NOR,me->short());
    foreach (object ob in all_inventory(me))
    {
        debug_message(sprintf(" - %O\n", ob));
        str += sprintf("[   %s              ]\n",ob->short());
    }
    write(str);
    return 1;
}
