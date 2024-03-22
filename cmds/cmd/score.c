// score.c
#include <ansi.h>

int main(object me, string arg)
{
    string str;
    string cl = me->colourStr();

    str = sprintf(YEL+"----------- Ant "+NOR+cl+"%s"+NOR+"(%s)"+YEL+" -----------\n"+NOR
                    +"[Life %s Nutrition %s Power %s ]\n"
                    +"\n"
                    ,
                    me->query("name"),file_name(me),
                    HIG + me->query("hp") +"%%"+ NOR,HIG + me->query("food") +"%%"+ NOR,
                    HIG + me->query("power") + NOR
                );
    write(str);
    return 1;
}
