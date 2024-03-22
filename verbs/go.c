/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-04-02 17:41:08
 * @LastEditTime: 2022-04-02 20:23:11
 * @LastEditors: 雪风
 * @Description:
 *  https://bbs.mud.ren
 */
inherit VERB;

#include <ansi.h>
#include <type.h>

protected void create()
{
    verb::create();
    setVerb("go");
    setSynonyms("move");
    setRules("STR", "into STR");
    setErrorMessage("Where to go?");
}

mixed can_go_str(string dir, string str)
{
    object me = this_player();
    object env = environment(me);
    object dest;
    mapping exits;
    mixed exit;

    if(classp(me))
    {
        me->save();
    }

    if (!me->query("area_info") && (!mapp(exits = env->query("exits")) || undefinedp(exit = exits[dir])))
    {
        return RED "No way." NOR;
    }

    if (me->query("food") && to_int(me->query("food"))<=0 )
    {
        return RED "You have no nutrition. Consider eating something." NOR;
    }

    if (me->is_fighting())
    {
        return YEL "You failed to escape ~ " NOR;
    }

    switch (typeof(exit))
    {
    case T_STRING:
        if (!objectp(dest = load_object(exit)))
        {
            return sprintf("Something wrong. You cannot move to %s. ", exit);
        }
        break;
    case T_MAPPING:
        if (undefinedp(exit["filename"]) || undefinedp(exit["x_axis"]) || undefinedp(exit["y_axis"]))
        {
            return sprintf("Something wrong. You cannot move to %s.", dir);
        }
        if (!objectp(dest = load_object(exit["filename"])))
        {
            return sprintf("Something wrong. You cannot move to %s.\n", exit["filename"]);
        }
        break;
    default:
        return env->is_area() || "Something wrong. Please contact admin or programmer.";
    }

    return 1;
}

int do_go_str(string dir, string str)
{
    object me = this_player();
    object env = environment(me);
    mapping exits = env->query("exits");
    mixed exit;
    object dest;

    if (env->is_area())
        return env->area_go(me, dir);

    exit = exits[dir];
    dest = stringp(exit) ? load_object(exit) : load_object(exit["filename"]);

    if (dest->is_area())
    {
        dest->area_move(me, exit["x_axis"], exit["y_axis"]);
    }
    else
    {
        msg("info", "$ME left here.", me, environment(me), ({me}));
        me->move(dest);
        msg("info", "$ME passed through.", me, environment(me), ({me}));
    }

    return 1;
}
