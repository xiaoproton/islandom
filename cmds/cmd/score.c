// score.c
#include <ansi.h>

int main(object me, string arg)
{
    string str;
    string cl;
    int power;
    string title;

    cl = me->colourString();
    power = to_int(me->query("power"));
    title = "Newbie Ant";
    if(power<50)
    {
        title = "Newbie Ant";
    }
    else if(power>=50 && power<100)
    {
        title = "Ordinary Ant";
    }
    else if(power>=100 && power<200)
    {
        title = "Elite Ant";
    }
    else if(power>=200 && power<1000)
    {
        title = "Leader Ant";
    }
    else if(power>=1000)
    {
        title = "Elder Ant";
    }

    str = sprintf(YEL+"----------- "+title+" "+NOR+cl+"%s"+NOR+YEL+" -----------\n"+NOR
                    +"[ Health %s      Nutrition %s        Power %s ]\n"
                    +"\n"
                    ,
                    me->short(),
                    HIG + me->query("hp") +"%"+ NOR,HIG + me->query("food") +"%"+ NOR,
                    HIG + me->query("power") + NOR
                );
    write(str);
    return 1;
}
