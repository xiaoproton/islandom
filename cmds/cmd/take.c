// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj;
    if(!arg||arg=="")
    {
        notify_fail("What do you want to pick up?");
    }
    debug_message("arg = "+arg);
    obj=load_object(arg);
    if(!obj)
    {
        debug_message("obj = "+obj->getruid());
        me->make_inventory(obj);
        debug_message("make_inventory done");
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
