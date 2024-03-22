inherit __DIR__ "user6";


void heart_beat()
{
    int hp,power,food;

    hp = to_int(query("hp"));
    power = to_int(query("power"));
    food = to_int(query("food"));

    if(food>20 && hp<100)
    {
        hp = hp + to_int(log2(power));
        food = food - 1;
    }
    if(hp>100)
        hp = 100;
    set("food", food);
    set("hp", hp);
    save();
}
