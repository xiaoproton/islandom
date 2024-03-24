inherit "/inherit/user6";


void heart_beat()
{
    int hp,power,food;
    int rate;
    mixed env;

    rate = 1;

    ::heart_beat();

    if(random(5)<1)  //trying this every 5 heart-beats
    {
        hp = to_int(query("hp"));
        food = to_int(query("food"));
        env = environment(this_object());
        if(env->shortfilename()=="resting_healing")
        {
            rate = 2; //for recovering hp

            //slowly recover nutrition
            if(food<50 && random(4)<1)
            {
                food += 1;
                set("food", food);
                write("You have recovered a bit of nutrition by eating the fungi around here.");
                save();
            }
        }

        //recovering hp
        if(food>20 && hp<100)
        {
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
            else
                write("Your body is recovering by consuming nutrition...\n");
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
