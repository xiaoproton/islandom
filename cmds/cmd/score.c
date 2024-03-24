// score.c
#include <ansi.h>

string taskDescr(int power)
{
    if(power<=2)
    {
        return "Use 'look' and 'n/e/s/w/' to move around\n"
                + "Use 'look' and 'take food' to get food\n"
                + "Use 'eat' to take care of yourself\n"
                + "Go to 'Queen Chamber' to 'feed queen'\n"
                + "Go to 'Egg Chamber' to 'nurse egg'\n";
    }
    else if(power<=5)
    {
        return "Go to 'Queen Chamber' to 'feed queen'\n"
                + "Use 'take egg' and 'drop egg' to move it to 'Egg Chamber'\n"
                + "Go to 'Larva Chamber' to 'feed larva'\n"
                + "Use 'take larva' and 'drop larva' to move it to 'Larva Chamber'\n"
                + "Go to 'Pupa Chamber' to 'nurse pupa'\n";
    }
    else if(power<=10)
    {
        return "Use 'take larva' and 'drop larva' to move it to 'Larva Chamber'\n"
                + "Go to 'Pupa Chamber' to 'nurse pupa'\n"
                + "Find 'Resting and Healing' place\n"
                + "Go to outside via 'Main Entrance' for more food\n"
                + "Use more food to 'feed queen' and 'feed larva'\n";
    }
    else if(power<=20)
    {
        return "Find 'Resting and Healing' place\n"
                + "Go to outside via 'Main Entrance' for more food\n"
                + "Walk away from 'Main Entrance' to fight\n"
                + "Use more food to 'feed queen' and 'feed larva'\n"
                + "keep doing 'nurse egg' and 'nurse pupa'\n";
    }
    else if(power<=50)
    {
        return "Go to outside via 'Main Entrance' for more food\n"
                + "Walk away from 'Main Entrance' to fight\n"
                + "Walk further way the 'marking' places to fight\n"
                + "Ask fields to join this game and help them\n"
                + "help others\n";
    }
    else
    {
        return "Ask fields to join this game and help them\n"
                + "help others\n";
    }
}

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
                    +YEL+"------------------------------------------------------------\n"+NOR
                    +"\n"
                    +"---------- Tasks you could do at your power level---------  \n"
                    +"%s "
                    +"------------------------------------------------------------\n"
                    ,
                    me->short(),
                    HIG + me->query("hp") +"%"+ NOR,HIG + me->query("food") +"%"+ NOR,
                    HIG + me->query("power") + NOR,
                    HIK+ taskDescr(me->query("power"))+NOR
                );
    write(str);
    return 1;
}
