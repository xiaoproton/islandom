// feed.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed feedee;
    mixed ob_list;
    mixed foundObj;
    int nutrition;
    int addition=30+random(10);
    int num;

    if(!arg||arg=="")
    {
        notify_fail("Whom do you want to feed?");
    }
    debug_message(sprintf("present %s got %O", arg, present(arg)));
    foundObj=find_object(arg);
    debug_message(sprintf("foundObj = %O",foundObj));
    ob_list=environment(me)->query("objects");
    debug_message(sprintf("ob_list = %O",ob_list));

    foreach( feedee,num in ob_list)
    {
        debug_message(sprintf("obj = %O",obj));
        if(feedee->shortfilename()==arg)
        {
            foreach (object fd in all_inventory(me))
            {
                if(fd->shortfilename()=="food")
                {
                    fd->destruct();
                    nutrition = to_int(feedee->query("food"));
                    nutrition += addition;
                    feedee->set("food",nutrition);
                    write(sprintf(GRN+"You fed a piece of food to %s.\n "
                                    +"Their nutrition (%d) has increased in their body now.\n"+NOR
                                feedee->short(),addition));
                    me->consume(3);
                    return 1;

                }
            }
            notify_fail("You do not have food in your inventory.\n");
            return 0;
        }
    }

    debug_message("no npc");
    notify_fail("There is no "+arg+" around.");
    return 0;

}
