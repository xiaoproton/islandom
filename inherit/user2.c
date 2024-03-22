inherit __DIR__ "user1";


void consume(int level) //smallest task, consumption level = 1, normal task consumption level = 10, biggest task 20
{
    int food, desire,spirit;
    this_object()->query("gender");
    food = to_int(this_object()->query("food"));
    desire = to_int(this_object()->query("desire"));
    spirit = to_int(this_object()->query("spirit"));

    //consume
    food = food - level;

    //recover
    food = food + to_int(level * log2(spirit));
    desire = desire + to_int(0.5 * level * log2(spirit));

    //
    if(food<0)
        food = 0;
    if(desire>100)
        desire = 100;
    if(food>100)
        food = 100;

}

// apply函数：如果用户对象中有process_input()，驱动会将玩家所有输入传入这里
// 如果 process_input() 方法返回字符串，此字符串会取代玩家的输入；如果返回 0 则保持玩家输入的内容不变；如果返回 1 则完全过滤掉此输入内容，不再做任何处理。
mixed process_input(string verb)
{
    string *word = explode(verb, " ");
    mapping alias = ([
        "s":"go south",
        "n":"go north",
        "w":"go west",
        "e":"go east",
       "sd":"go southdown",
       "nd":"go northdown",
       "wd":"go westdown",
       "ed":"go eastdown",
       "su":"go southup",
       "nu":"go northup",
       "wu":"go westup",
       "eu":"go eastup",
       "sw":"go southwest",
       "se":"go southeast",
       "nw":"go northwest",
       "ne":"go northeast",
        "d":"go down",
        "u":"go up",
     "chat":"shout",
      "who":"users",
        "i":"all_inventory",
        "shuxing":"score",
        "xue":"learn",
        "chi":"eat",
      // "ls":"get_dir",
      // "sa":"area_set",
    ]);

    // verb = lower_case(verb);

    switch (verb[0])
    {
    case '.':
        return "say " + verb[1..];
    }

    if (sizeof(word) && !undefinedp(alias[word[0]]))
    {
        word[0] = alias[word[0]];
        return implode(word, " ");
    }

    if(verb[0..2]=="go ")
    {
        consume(1);
    }
    if((verb=="south")||(verb=="north")||(verb=="west")||(verb=="east")||(verb=="up")||(verb=="down") )
    {
        consume(1);
    }
    if(verb[0..4]=="learn")
    {
        consume(2);
    }
    if(verb[0..4]=="fight")
    {
        consume(8);
    }

    return verb;
}
