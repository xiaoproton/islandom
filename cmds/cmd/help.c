#include <ansi.h>


int main(object me, string arg)
{
    string help = @HELP
    $YEL$-------------------------------Peronmone Handbook----------------------------------$NOR$

    User Your Keyboard to type the command：
        $CYN$north,south,east,west OR n,s,e,w$NOR$      move to different directions
        $CYN$ne,se,nw,sw$NOR$                           move to different directions
        $CYN$up,down OR u,d$NOR$                        move to different heights
        $CYN$look OR l$NOR$                             look around
        $CYN$help$NOR$                                  check this handbook or command details
        $CYN$eat$NOR$                                   eat food
        $CYN$take$NOR$                                  pick up and carry something in your inventory
        $CYN$drop$NOR$                                  move something out of your inventory
        $CYN$nurse$NOR$                                 take care of something/someone
        $CYN$inventory OR i$NOR$                        check what you are carrying
        $CYN$score OR s$NOR$                            check your status and power
        $CYN$fight$NOR$                         try to kill someone
        $CYN$say$NOR$                                   say to everyone in the current room/place
        $CYN$chat$NOR$                                  talk to everyonr online
        $CYN$who$NOR$                                   list all players online
        $CYN$snoop$NOR$                                 monitor someone
        $CYN$quit$NOR$                                  quit this game
    $YEL$-----------------------------------------------------------------------------------$NOR$
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
