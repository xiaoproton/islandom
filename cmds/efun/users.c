// 列出游戏所有玩家对象
#include "ansi.h"

int main(object me, string arg)
{
    string colour;
    string cl;
    //printf("%O\n", users());
    foreach(object u in users())
    {
        colour= u->query("colour") || "b";
        if(colour=="b")
            cl = BLU;
        if(colour=="y")
            cl =  YEL;
        if(colour=="p")
            cl =  MAG;
        if(colour=="g")
            cl =  GRN;
        if(colour=="r")
            cl =  RED;
        write(" * " + cl + u->short() + NOR +"\n");
    }

    return 1;
}
