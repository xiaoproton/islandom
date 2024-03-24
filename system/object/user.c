inherit "/inherit/user6";


void heart_beat()
{
    int hp,power,food;
    int rate = 1;
    obj env;

    if(random(5)<1)  //trying this every 5 heart-beats
    {
        hp = to_int(query("hp"));
        food = to_int(query("food"));
        //recovering hp
        if(food>20 && hp<100)
        {
            env = environment(this_object());
            if(env->shortfilename()=="resting_healing") rate = 2;

            power = to_int(query("power"));

            hp = hp + rate*to_int(log2(power+1));
            if(random(rate)==0)
                food = food - 1;

            if(hp>100)
                hp = 100;
            set("food", food);
            set("hp", hp);
            if(hp==100)
                write("You have fully recovered.");
            save();
        }
    }


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
