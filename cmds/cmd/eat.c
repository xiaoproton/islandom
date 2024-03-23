// eat.c
#include <ansi.h>

int main(object me, string arg)
{
    int nutrition;
    int addition=30+random(10);
    foreach (object ob in all_inventory(me))
    {
        if(ob->shortfilename()=="food")
        {
            ob->destruct();
            nutrition = to_int(me->query("food"));
            nutrition += addition;
            me->set("food",nutrition);
            write(sprintf(GRN+"You ate a piece of food.\n "
                             +"Your have more nutrition (%d) in your body now.\n"+NOR
                        ,addition));
            return 1;

        }
    }
    notify_fail("You do not have food in your inventory.\n");
    return 0;
}
