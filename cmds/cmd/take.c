// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    mixed ob_list;
    //mixed foundObj;
    int power;
    int num;
    object real_obj;
    if(!arg||arg=="")
    {
        notify_fail("What do you want to pick up?");
    }
    debug_message(sprintf("present %s got %O", arg, present(arg)));
    //foundObj=find_object(arg);
    //debug_message(sprintf("foundObj = %O",foundObj));
    ob_list=environment(me)->query("objects");
    debug_message(sprintf("ob_list = %O",ob_list));
    if(ob_list && sizeof(ob_list)>0)
    {
        foreach( obj,num in ob_list)
        {

            debug_message(sprintf("obj = %O",obj));
            real_obj = find_object(obj);
            debug_message(sprintf("real_obj = %O",real_obj));
            if(real_obj->shortfilename()==arg)
            {
                power = to_int(me->query("power"));
                if(real_obj->can_be_pickedup(power))
                {

                    me->make_inventory(real_Obj);
                    real_obj->move_object(VOID_OB);
                    write(GRN+"You have picked up "+obj->short()+" and placed into your inventory.\n"+NOR);
                    destruct(real_obj);
                    me->save();
                    return 1;
                }
                else
                {
                    notify_fail("You cannot take away "+arg+". too heavy? or inappropriate?");
                    return 0;
                }
            }
        }
    }

    debug_message("no obj");
    notify_fail("There is no "+arg+" around.");
    return 0;

}
