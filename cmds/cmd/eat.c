// eat.c
#include <ansi.h>


int main(object me, string arg)
{
    int nutrition;
    int addition=50+random(20);
    nutrition = to_int(me->query("food"));
    if(nutrition>=100)
    {
        notify_fail("You are full of nutrition. No need to waste food.\n");
        return 0;
    }
    foreach (object ob in all_inventory(me))
    {
        if(ob->shortfilename()=="food")
        {
            ob->move_object(VOID_OB);
            destruct(ob);
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
