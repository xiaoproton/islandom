// inventory.c
#include <ansi.h>

int main(object me, string arg)
{
    string str;
    str = sprintf(YEL+"----------- Ant "+NOR+cl+"%s 's Inventory"+NOR+YEL+" -----------\n"+NOR
    foreach (object ob in all_inventory(me))
    {
        printf(" - %O\n", ob);
        str += sprintf("[   %s              ]\n",ob->short());
    }
    write(str);
    return 1;

}
