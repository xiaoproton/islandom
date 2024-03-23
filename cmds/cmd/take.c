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
    int myInvNum;
    mixed myInvList;
    if(!arg||arg=="")
    {
        notify_fail(RED "What do you want to pick up?" NOR);
        return 0;
    }
    power = to_int(me->query("power"));
    myInvList=all_inventory(me);
    myInvNum = sizeof(myInvList);
    if(myInvNum>power+1)
    {
        notify_fail(RED "You are not strong enough to carry more items." NOR);
        return 0;
    }

    ob_list = all_inventory(environment(me));   //use all_inv not query("objects"), to get actual clones
    debug_message(sprintf("ob_list = %O",ob_list));
    if(ob_list && sizeof(ob_list)>0)
    {
        foreach( obj in ob_list)
        {
            if(obj->shortfilename()==arg)
            {
                if(obj->can_be_pickedup(power))
                {
                    debug_message(sprintf("obj %O",obj));
                    obj->move_object(VOID_OB);
                    newobj=me->make_inventory(base_name(obj));  //use base_name, not file_name, to remove # part
                    debug_message(sprintf("newobj = %O",newobj));
                    write(GRN+"You have picked up "+obj->short()+" and placed into your inventory.\n"+NOR);
                    destruct(obj);
                    me->save();
                    return 1;
                }
                else
                {
                    notify_fail(RED "You cannot take away "+arg+". too heavy? or inappropriate?" NOR);
                    return 0;
                }
            }
        }
    }

    debug_message("no obj");
    notify_fail(RED "There is no "+arg+" around." NOR);
    return 0;

}
