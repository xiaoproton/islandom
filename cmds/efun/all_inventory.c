// all_inventory.c
int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        print_r(all_inventory(me));
    }
    else if (ob = load_object(arg))
    {
        print_r(all_inventory(ob));
    }
    else
    {
        cecho("Objects not found " + arg);
    }

    return 1;
}
