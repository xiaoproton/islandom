#include <ansi.h>


int main(object me, string arg)
{
    string help = @HELP
    $YEL$-----------------------仙女岛旅行者手册--------------------------$NOR$

    你可以用键盘输入如下基本指令来实现不同的动作：
        $CYN$north,south,east,west或n,s,e,w$NOR$      走向不同的地方
        $CYN$up,down或u,d$NOR$                        走向不同的高度
        $CYN$look或l$NOR$                             查看周围的情况
        $CYN$help或help加其他命令$NOR$                 查看该手册或其他命令详情
        $CYN$learn加技能名或xue加技能名$NOR$            学习某种技能
        $CYN$inventory或i$NOR$                        查看自己携带的物品
        $CYN$score或shuxing$NOR$                      查看自己的状态技能等
        $CYN$go$NOR$                                  快速去某个地方
        $CYN$fight$NOR$                               打打杀杀
        $CYN$quit$NOR$                                离开仙女岛
HELP;
    string file;

    if (!arg)
    {
        write(ansi(help));
    }
    else if (file_size(file = "/cmds/cmd/" + arg + ".c") > 0 || file_size(file = "/cmds/test/" + arg + ".c") > 0 || file_size(file = "/cmds/efun/" + arg + ".c") > 0 || file_size(file = "/verbs/" + arg + ".c") > 0)
    {
        notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
        return file->help();
    }
    else
    {
        return notify_fail("没有这个指令。\n");
    }

    return 1;
}
