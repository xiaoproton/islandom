// take.c
#include <ansi.h>

int main(object me, string arg)
{
    mixed obj=load_object(arg);
    if(!obj)
    {
        me->make_inventory(arg);
        write("You have picked "+obj->short()+" into your inventory.");
        return 1;
    }
    else
    {
        notify_fail("There is no "+arg+" around.");
        return 0;
    }

}
