// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    mixed ob_list;
    //mixed foundObj;
    int power;
    int num;
    object newobj;
    if(!arg||arg=="")
    {
        notify_fail("What do you want to pick up?");
    }

    ob_list = all_inventory(environment(me));
    debug_message(sprintf("ob_list = %O",ob_list));
    if(ob_list && sizeof(ob_list)>0)
    {
        foreach( obj in ob_list)
        {
            if(obj->shortfilename()==arg)
            {
                power = to_int(me->query("power"));
                if(obj->can_be_pickedup(power))
                {
                    debug_message(sprintf("obj %O",obj));
                    obj->move_object(VOID_OB);
                    newobj=me->make_inventory(base_name(obj));
                    debug_message(sprintf("newobj = %O",newobj));
                    write(GRN+"You have picked up "+obj->short()+" and placed into your inventory.\n"+NOR);
                    obj->destruct(obj);
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
