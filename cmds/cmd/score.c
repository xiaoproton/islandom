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
                    geteuid(),getuid(),
                    WHT + me->query("hp") + NOR, HIG + "100" + NOR,
                    WHT + me->query("food") + NOR, HIG + "100" + NOR,
                    WHT + me->query("desire") + NOR, HIG + "100" + NOR,
                    WHT + me->query("power") + NOR,WHT + me->query("tech") + NOR,WHT + me->query("glamour") + NOR
                );
    write(str);
}
