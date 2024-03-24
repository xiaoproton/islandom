// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    mixed ob_list;
    //mixed foundObj;
    int num;
    int nutrition;
    int power;

    if(!arg||arg=="")
    {
        notify_fail(RED "What do you want to take care of?" NOR);
        return 0;
    }
    nutrition = to_int(me->query("food"));
    if(nutrition<10)
    {
        notify_fail(RED "You are too hungry. Take care of yourself first." NOR);
        return 0;
    }
    ob_list = all_inventory(environment(me));   //use all_inv not query("objects"), to get actual clones

    foreach( obj in ob_list)
    {
        if(obj->shortfilename()==arg)
        {
            me->consume(4);
            write(GRN+"You spent energy and nutrition to nurse "+obj->short()+".\n"+NOR);
            if(arg=="egg" && random(10)<2)
            {
                if(random(3)<1)
                {
                    write(sprintf(HIY+"The egg has just incubated to be a larva thanks to your caring!\n"+NOR));
                    destruct(obj);
                    environment(me)->make_inventory("/world/world/item/larva");
                }
                else
                {
                    write(sprintf(YEL+"You are feeling your power has increased by keeping nursing eggs.\n"+NOR));
                    power = to_int(me->query("power"));
                    me->set("power",(power+1));
                    me->save();
                }

            }
            if(arg=="pupa" && random(10)<2)
            {
                if(random(3)<1)
                {
                    write(sprintf(HIY+"HOORAY! The pupa has just turned into a new adult NPC ant thanks to your nusing!\n"+NOR));
                    write(sprintf(HIY+"CONGRATS! We are one-step closer to our goal!\n"+NOR));
                    write(sprintf(HIY+"So far, there have been %d New NPC Ants born.\n"+NOR,COLONY_D->increase_new_ant_total()));
                    shout(sprintf(HIY+"GREAT WORK! %s has just made one more NPC Ant born!\n"+NOR,me->short()));
                    destruct(obj);
                    environment(me)->make_inventory("/world/world/item/npc-ant");
                }
                else
                {
                    write(sprintf(YEL+"You are feeling your power has increased by keeping nursing pupae.\n"+NOR));
                    power = to_int(me->query("power"));
                    me->set("power",(power+1));
                    me->save();
                }

            }
            return 1;
        }
    }

    debug_message("no obj");
    notify_fail("There is no "+arg+" around.");
    return 0;

}
