#include <ansi.h>


int main(object me, string arg)
{
    string help = @HELP
    $YEL$-----------------------Hand--------------------------$NOR$

    User Your Keyboard to type the command：
        $CYN$north,south,east,west OR n,s,e,w$NOR$      move to different directions
        $CYN$up,down OR u,d$NOR$                        move to different height
        $CYN$look OR l$NOR$                             look around
        $CYN$help$NOR$                                  check this handbook or command details
        $CYN$eat$NOR$                                   eat food
        $CYN$take$NOR$                                  pick and carry something
        $CYN$inventory OR i$NOR$                        check what you are carrying
        $CYN$score OR s$NOR$                            check your status and attributes
        $CYN$fight$NOR$                                 try to kill something
        $CYN$quit$NOR$                                  quit this game
HELP;
    string file;

    if (!arg)
    {
        write(ansi(help));
    }
    else if (file_size(file = "/cmds/cmd/" + arg + ".c") > 0 || file_size(file = "/cmds/test/" + arg + ".c") > 0 || file_size(file = "/cmds/efun/" + arg + ".c") > 0 || file_size(file = "/verbs/" + arg + ".c") > 0)
    {
        notify_fail("The command exists, but no more details. \n");
        return file->help();
    }
    else
    {
        return notify_fail("The command does not exists\n");
    }

    return 1;
}
