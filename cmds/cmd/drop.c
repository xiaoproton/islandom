// drop.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    mixed ob_list;
    //mixed foundObj;
    int power;
    int num;
    object newobj;
    int myInvNum;
    mixed myInvList;
    if(!arg||arg=="")
    {
        notify_fail(RED "What do you want to move out?" NOR);
    }
    power = to_int(me->query("power"));


    ob_list = all_inventory(me);   //use all_inv not query("objects"), to get actual clones
    //debug_message(sprintf("ob_list = %O",ob_list));
    if(ob_list && sizeof(ob_list)>0)
    {
        foreach( obj in ob_list)
        {
            if(obj->shortfilename()==arg)
            {

                    //debug_message(sprintf("obj %O",obj));
                    obj->move_object(VOID_OB);
                    newobj=environment(me)->make_inventory(base_name(obj));  //use base_name, not file_name, to remove # part
                    //debug_message(sprintf("newobj = %O",newobj));
                    write(GRN+"You have dropped "+obj->short()+".\n"+NOR);
                    if(obj->shortfilename()=="egg" && environment(me)->shortfilename()=="egg_chamber")
                    {
                        if(random(10)<2)
                        {
                            write(sprintf(YEL+"You are feeling your power has increased by keeping moving eggs.\n"+NOR));
                            power = to_int(me->query("power"));
                            me->set("power",(power+1));
                            me->save();
                        }
                        else
                        {
                            write(sprintf(GRN+"Egg is incubating healthier in Egg Chamber.\n"+NOR));
                        }
                    }
                    if(obj->shortfilename()=="larva" && environment(me)->shortfilename()=="larva_chamber")
                    {
                        if(random(10)<2)
                        {
                            write(sprintf(YEL+"You are feeling your power has increased by keeping moving larvae.\n"+NOR));
                            power = to_int(me->query("power"));
                            me->set("power",(power+1));
                            me->save();
                        }
                        else
                        {
                            write(sprintf(GRN+"Larva is growing healthier in Larva Chamber.\n"+NOR));
                        }
                    }
                    destruct(obj);
                    me->save();
                    return 1;

            }
        }
    }

    debug_message("no obj");
    notify_fail(RED "There is no "+arg+" in your inventory." NOR);
    return 0;

}
