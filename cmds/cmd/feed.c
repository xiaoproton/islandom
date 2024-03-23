// feed.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed feedee;
    mixed ob_list;
    //mixed foundObj;
    int nutrition;
    int addition=30+random(10);
    int num;
    string feedeeType;
    int power;
    object newob;

    if(!arg||arg=="")
    {
        notify_fail(RED+"Whom do you want to feed?"+NOR);
    }

    ob_list=environment(me)->query("objects");
    debug_message(sprintf("ob_list = %O",ob_list));

    foreach( feedee,num in ob_list)
    {
        debug_message(sprintf("obj = %O",feedee));
        if(feedee->shortfilename()==arg)
        {
            foreach (object fd in all_inventory(me))
            {
                if(fd->shortfilename()=="food")
                {
                    feedeeType = feedee->shortfilename();
                    if(feedeeType=="user")
                    {
                        fd->move_object(VOID_OB);
                        destruct(fd);
                        nutrition = to_int(feedee->query("food"));
                        nutrition += addition;
                        if(nutrition>100)
                            nutrition = 100;
                        feedee->set("food",nutrition);
                        msg("success", "$ME fed a piece of food to $YOU.\n"
                                        +"The nutrition in $YOU has increased by %d", me, feedee,addition);
                        me->consume(3);
                        return 1;
                    }
                    else if(feedeeType=="queen")
                    {
                        fd->move_object(VOID_OB);
                        destruct(fd);
                        if(random(10)<2)
                        {
                            if(random(3)<1){
                                environment(me)->make_inventory("/world/world/item/egg");
                                write(sprintf(YEL+"The Queen has just produce a new egg,\n"
                                                    +"thank to your feeding.\n"+NOR));
                            }
                            else
                            {
                                write(sprintf(YEL+"You are feeling your power has increased by keeping feeding the Queen.\n"+NOR));
                                power = to_int(me->query("power"));
                                me->set("power",(power+1));
                                me->save();
                            }

                        }
                        else
                        {
                            write(sprintf(GRN+"Through Pheromone, the Queen tells you she's appreciated your food.\n"
                                            +"She may be able to produce more eggs now.\n"+NOR));
                        }
                        me->consume(3);
                        return 1;
                    }
                    else if(feedeeType=="larva")
                    {
                        fd->move_object(VOID_OB);
                        destruct(fd);
                        if(random(10)<2)
                        {
                            write(sprintf(YEL+"You are feeling your power has increased by keeping feeding larvea.\n"+NOR));
                            power = to_int(me->query("power"));
                            me->set("power",(power+1));
                            me->save();
                        }
                        else
                        {
                            write(sprintf(GRN+"Larva is being growing more thanks to your feeding.\n"+NOR));
                        }
                        me->consume(3);
                        return 1;
                    }
                    else
                    {
                        notify_fail("They do not need to be fed.\n");
                        return 0;
                    }

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
