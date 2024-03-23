// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    mixed ob_list;
    //mixed foundObj;
    int num;
    if(!arg||arg=="")
    {
        notify_fail("What do you want to pick up?");
    }
    debug_message(sprintf("present %s got %O", arg, present(arg)));
    //foundObj=find_object(arg);
    //debug_message(sprintf("foundObj = %O",foundObj));
    ob_list=environment(me)->query("objects");
    debug_message(sprintf("ob_list = %O",ob_list));

    foreach( obj,num in ob_list)
    {
        debug_message(sprintf("obj = %O",obj));
        if(obj->shortfilename()==arg)
        {
            me->make_inventory(obj);
            debug_message("make_inventory done");
            //obj->move_object(me);
            //debug_message("move_object done");
            write(GRN+"You have picked up "+obj->short()+" and placed into your inventory.\n"+NOR);
            return 1;
        }
    }

    debug_message("no obj");
    notify_fail("There is no "+arg+" around.");
    return 0;

}
