// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    mixed ob_list;
    mixed foundObj;
    if(!arg||arg=="")
    {
        notify_fail("What do you want to pick up?");
    }
    debug_message("arg = "+arg);
    foundObj=find_object(arg);
    debug_message(sprintf("foundObj = %O",foundObj);
    ob_list=environment(me)->query("objects");
    debug_message(sprintf("ob_list = %d",sizeof(ob_list)));
    foreach(mixed ob in ob_list)
    {
        debug_message(sprintf("obj = %s",ob));
        debug_message(sprintf("obj = %s",ob->geteuid()));
    }
    if(!obj)
    {
        debug_message(sprintf("obj = %O",obj));
        //me->make_inventory(obj);
        //debug_message("make_inventory done");
        obj->move_object(me);
        debug_message("move_object done");
        write("You have picked up "+obj->short()+" and placed into your inventory.");
        return 1;
    }
    else
    {
        debug_message("no obj");
        notify_fail("There is no "+arg+" around.");
        return 0;
    }

}
