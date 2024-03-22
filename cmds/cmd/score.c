// score.c
#include <ansi.h>

int main(object me, string arg)
{
    string str;
    string cl = MAG;
    if(me->query("gender")=="男")
    {
        cl = BLU;
    }
    str = sprintf(YEL+"--------旅行者 "+NOR+cl+"%s"+NOR+YEL+" 的各项属性-------\n"+NOR
                    +"[生命 %s 食物 %s 情欲 %s ]\n"
                    +"[战力 %s  性技 %s  魅惑 %s ]\n"
                    +"[灵力 %s  ]"
                    +"\n"
                    ,
                    me->query("name"),
                    HIG + me->query("hp") +"%%"+ NOR,HIG + me->query("food") +"%%"+ NOR,HIG + me->query("desire") +"%%"+ NOR,
                    HIG + me->query("power") + NOR,HIG + me->query("tech") + NOR,HIG + me->query("glamour") + NOR,
                    HIG + me->query("spirit") + NOR
                );
    write(str);
    return 1;
}
