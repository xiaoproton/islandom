// take.c
#include <ansi.h>

int main(object me, string arg)
{
    if(!arg||arg=="")
    {
        notify_fail("What do you want to pick up?");
    }
    mixed obj=load_object(arg);
    if(!obj)
    {
        me->make_inventory(obj);
        write("You have picked up "+obj->short()+" and placed into your inventory.");
        return 1;
    }
    else
    {
        notify_fail("There is no "+arg+" around.");
        return 0;
    }

}
