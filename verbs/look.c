inherit VERB;

#include <ansi.h>

int look_room(object me, object env);
string desc_of_objects(object *obs);
string list_all_inventory_of_object(object me, object env);
int look_living(object me, object ob);

protected void create()
{
    verb::create();
    setVerb("look");
    setSynonyms("l");
    setRules("", "STR", "OBJ", "at STR", "at OBJ", "on OBJ", "in OBJ", "inside OBJ",
             "at OBJ in OBJ", "OBJ inside OBJ", "at OBJ on OBJ", "at STR on OBJ");
    setErrorMessage("What would you like to look at?");
}

mixed can_look()
{
    object env = environment(this_player());
    if (!env || !env->query("short") && !env->is_area())
        return "Foggy and blurry. Nothing can be seen.";
    else
        return 1;
}

mixed can_verb_rule(mixed *data...)
{
    // debug_message(sprintf("can_verb_rule : %O", data));
    return can_look();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_look();
}

mixed direct_look_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}

mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_look();
}

mixed direct_verb_word_obj(mixed *data...)
{
    // debug_message(sprintf("direct_verb_word_obj : %O", data));
    return can_look();
}

mixed do_look()
{
    object me = this_player();
    object env = environment(me);

    return look_room(me, env);
}

mixed do_look_at_obj(object ob)
{
    object me = this_player();

    if (living(ob))
    {
        look_living(me, ob);
    }
    else
    {
        printf("%s\n", (ob->long()||ob->query("long")));
    }

    return 1;
}

mixed do_look_at_obj_in_obj(object ob1, object ob2, string id1, string id2)
{
    printf("%s\n", ob1->long());
    return 1;
}

mixed do_look_obj(object ob)
{
    return do_look_at_obj(ob);
}

mixed do_look_in_obj(object ob)
{
    if (sizeof(all_inventory(ob)))
    {
        cecho(sprintf("In %s, there is \n%s", ob->short(), list_all_inventory_of_object(ob, ob)));
    }
    else
    {
        cecho(sprintf("In %s, there is nothing.", ob->short()));
    }

    return 1;
}

mixed do_look_at_str(string str, string arg)
{
    object me = this_player();
    object env = environment(me);
    mapping exits = env->query("exits");
    object ob;
    mixed item_desc;

    //debug_message(sprintf("query items %O",env->query("items")));
    //debug_message(sprintf("query items/%s %O",str,env->query("items/" + str)));

    if (str == "here")
    {
        return do_look();
    }
    else if (stringp(exits[str]))
        return look_room(me, load_object(exits[str]));
    else if (mapp(exits[str]))
        cecho("You cannot see clearly for a big area.");
    else if (item_desc = env->query("items/" + str))
        cecho(evaluate(item_desc));
    //else if (ob = present(arg, env))
    else if (ob=env->myPresent(arg))
        return do_look_obj(ob);
    else
        cecho(getErrorMessage());

    return 1;
}

mixed do_look_str(string str, string arg)
{
    return do_look_at_str(str, arg);
}

mixed do_verb_rule(mixed *data...)
{
    //this is triggered by driver?
    debug_message(sprintf("do_verb_rule : %O", data));
    return 1;
}

// 查看环境(此方法推荐放在环境中)
int look_room(object me, object env)
{
    string str, *dirs;
    mapping exits;

    if (env->is_area())
    {
        return env->do_look(me);
    }

    str = sprintf(HIC + "%s" + NOR + "\n%s" + NOR,
                  env->short(),env->query("long"));

    if (mapp(exits = env->query("exits")))
    {
        dirs = keys(exits);

        if (sizeof(dirs) == 0)
            str += "    There is no obvious exit. \n";
        else if (sizeof(dirs) == 1)
            str += "    The only exit here is " + BOLD + dirs[0] + NOR + "。\n";
        else
            str += sprintf("    The obvious exits are " + BOLD + "%s" + NOR + " and " + BOLD + "%s" + NOR + ". \n",
                           implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs) - 1]);
    }
    else
    {
        str += "    No way to this direction. \n";
    }

    str += list_all_inventory_of_object(me, env);
    tell_object(me, str);
    return 1;
}

string desc_of_objects(object *obs)
{
    int i;
    string str;
    mapping list, unit;
    string short_name;
    string *ob;

    //debug_message(sprintf("desc_of_objects %d ",sizeof(obs)));

    if (obs && sizeof(obs) > 0)
    {
        str = "";
        list = ([]);
        unit = ([]);

        for (i = 0; i < sizeof(obs); i++)
        {
            short_name = (obs[i]->colourString()||"") + obs[i]->short() + NOR;
            debug_message("short_name "+short_name);

            list[short_name] += obs[i]->query_temp("amount") ? obs[i]->query_temp("amount") : 1;
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : " ";
        }

        ob = sort_array(keys(list), 1);
        for (i = 0; i < sizeof(ob); i++)
        {
            str += YEL+" * "+NOR;
            if (list[ob[i]] > 1)
                str += list[ob[i]] + unit[ob[i]] + ob[i] +YEL+" * "+NOR+ "\n";
            else
                str += ob[i] +YEL+" * "+NOR+ "\n";
        }
        return str;
    }

    return "";
}

string list_all_inventory_of_object(object me, object env)
{
    object *inv;
    object *obs;
    string str = "";

    if (!env || !me)
        return "";

    inv = all_inventory(env);
    //debug_message(sprintf("size inv of %s is %d",env->short(),sizeof(inv)));
    if (!sizeof(inv))
        return str;

    obs = filter_array(inv, (: $(me) != $1 :));
    str += desc_of_objects(obs);
    //debug_message(sprintf("list_all_inventory_of_object of %s returns %s",env->short(),str));
    return str;
}

int look_living(object me, object ob)
{
    string msg;
    string line = repeat_string("-*-", 12) + "\n";

    if (ob != this_player())
    {
        msg = "$ME looked $YOU as if $YOU is interesting.";
        msg("vision", msg, me, ob);
    }

    //debug_message("ob->short() "+ob->short());
    //debug_message("ob->appearance() "+ob->appearance());
    //debug_message("ob->query(power) "+ob->query("power"));
    msg = line;
    msg += sprintf("%s is a %s living creature. \n", ob->short(),ob->appearance());
    msg += sprintf("Power %d\n", ob->query("power"));
    msg += line;
    tell_object(me, msg);


    return 1;
}

int help(object me)
{
    write(@HELP
Command format: look ｜ l

Basic look, allows you to observe objects and look around environment.

When there are more than one objects, for example, 4 NPCs, you may specify the particular object by using

    l 1st n or l n 1
    l 2nd n or l n 2
    l 3rd n or l n 3
    l 4th n or l n 4

HELP );
    return 1;
}
