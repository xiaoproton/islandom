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
    str = sprintf(YEL+"--------旅行者 "+NOR+cl+"%s(%s)"+NOR+YEL+" 的各项属性-------\n"+NOR
                    +"[生命 %s/%s 食物 %s/%s 情欲 %s/%s]\n"
                    +"[战力  %s   性技  %s   魅惑  %s  ]\n"
                    +"\n"
                    ,
                    me->geteuid(),me->getuid(),
                    HIG + me->query("hp") + NOR, WHT + "100" + NOR,
                    HIG + me->query("food") + NOR, WHT + "100" + NOR,
                    HIG + me->query("desire") + NOR, WHT + "100" + NOR,
                    HIG + me->query("power") + NOR,HIG + me->query("tech") + NOR,HIG + me->query("glamour") + NOR
                );
    write(str);
}
