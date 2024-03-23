inherit __DIR__ "user6";


void heart_beat()
{
    int hp,power,food;

    hp = to_int(query("hp"));
    power = to_int(query("power"));
    food = to_int(query("food"));
    //recovering hp
    if(food>20 && hp<100)
    {
        hp = hp + to_int(log2(power+1));
        food = food - 1;
    }
    if(hp>100)
        hp = 100;
    set("food", food);
    set("hp", hp);
    save();
}

object make_inventory(string file)
{
    object ob;

    if(!objectp(ob = new(file)))
        return 0;
    ob->move(this_object());
    return ob;
}

int can_be_pickedup(int pwr)
{
    return 0;
}
