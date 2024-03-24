inherit VERB;

#include <ansi.h>

protected void create()
{
    verb::create();
    setVerb("fight");
    setSynonyms("kill", "hit");
    setRules("LIV");
    setErrorMessage("Who do you fight against?");
}

mixed can_fight_liv(mixed *data...)
{
    int nutrition;
    object me = this_player();

    debug_message(sprintf("can_fight_liv data %O",data));
    if(classp(me))
    {
        me->save();
        nutrition = to_int(me->query("food"));
        if(nutrition<20)
        {
            return RED "You are too hungry to fight. Eat something." NOR;
        }
    }
    // cecho(data);
    if (file_name(environment(me)) == START_ROOM)
    {
        return "This is a fight-free area.";
    }

    if (me->query("food") && to_int(me->query("food"))<=20 )
    {
        return RED "You don't have enough nutrition to support you to fight." NOR;
    }
    return me->can_fight() || HIY "You cannot fight." NOR;
}

mixed direct_fight_liv(object ob, string arg)
{
    if (ob == this_player())
        return HIM "Good Idea! But it is impossible." NOR;
    return ob->can_fight();
}

int do_fight_liv(object ob, string arg)
{
    string colour;
    object me = this_player();

    /*
    colour = ob->query("colour");
    if(colour!="r")
    {
        msg("warning", "You can only fight against a red-colour enemy. ");
        return 1;
    }
    */

    me->consume(8);
    msg("warning", "$ME put up your front claws, start attacking $YOU. ", me, ob);
    me->fight(ob);

    return 1;
}

int help(object me)
{
    write(@HELP
Command syntax: fight | hit | kill

fighting command. use it to try to kill other living creatures.

HELP );
    return 1;
}
