/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: login_ob.c
Description: 玩家登录连线对象
Author: xuefeng
Version: v1.0
Date: 2019-04-18
*****************************************************************************/
#define WELCOME "/system/etc/motd"
#include "ansi.h"

object loginuser;

void setup(string arg)
{

    if (!arg || arg == "")
    {
        write("User login name cannot be balnk. Please enter again: ");
        input_to("setup");
    }
    else
    {
        // log
        loginuser = new(USER_OB, arg);
        debug_message(ctime() + " " + query_ip_number(loginuser) + " " + arg);
        if(loginuser->load(arg))
        {
            //existing
            write("Please type your password: ");
            input_to("password");
        }else
        {
            //new
            write("Please enter your display name (please use a pronouceable name):");
            input_to("setname");
        }

    }
}

void password(string arg)
{
    if (!arg || arg == "")
    {
        write("Password cannot be blank. Please type it again: ");
        input_to("password");
    }
    else
    {
        if( sha1(arg)==loginuser->query("password") )
        {
            cecho("Login successfully.");
            this_object()->landing();
        }else
        {
            write("Wrong password. Try again: ");
            input_to("password");
        }
    }
}

void setname(string arg)
{
    debug_message(ctime() + " " + " setname " + arg);

    if (!arg || arg == "")
    {
        write("display name cannot be blank. Please type it again: ");
        input_to("setname");
    }
    else
    {
        loginuser->set("name", arg);
        debug_message(ctime() + " " + query_ip_number(loginuser) + " " + arg);
        write("Please choose your ant colour (b for blue, Y for yellow, p for pink):");
        input_to("setcolour");
    }
}

void setcolour(string arg)
{

    if (!arg || arg == "")
    {
        loginuser->set("colour", "y");
    }
    else if (arg == "p" || arg == "P" || arg == "pink" || arg == "Pink")
    {
        loginuser->set("colour", "p");
    }
    else if (arg == "b" || arg == "B" || arg == "Blue" || arg == "blue")
    {
        loginuser->set("colour", "b");
    }
    else if (arg == "y" || arg == "Y" || arg == "Yellow" || arg == "yellow")
    {
        loginuser->set("colour", "y");
    }
    else
    {
        loginuser->set("colour", "y");
    }
    write("Please set your password (no need to over-complicate it. 4-8 numbers/letters should be enough.): ");
    input_to("setpassword");
}

void setpassword(string arg)
{
    string encrypted;
    if (!arg || arg == "")
    {
        write("Password cannot be balnk. Try again: ");
        input_to("setpassword");
    }
    else
    {
        encrypted=sha1(arg);
        //debug_message(ctime() + " " + query_ip_number(loginuser) + " " + encrypted);
        loginuser->set("password", encrypted);
        loginuser->save();
        cecho("Congrats! You are officially an Alien Ant.");
        this_object()->landing();
    }
}

void landing()
{
    object cuurentme;
    //use the user
    cuurentme = this_object();
    exec(loginuser, cuurentme);
    destruct(cuurentme);
    write(YEL+"One second ago, you were a human being sitting in front a screen.\n"+NOR);
    write(YEL+"One second later, you are an Alien Ant, crawling in "+HBMAG+"Queen Islandom"+NOR+" "+YEL+"'s ant colony. \n"+NOR);
    write(WHT+"Hint: use your keyboard type "+GRN+" look "+NOR+"OR"+GRN+" l "+NOR+" "+WHT+"to look around. Or, type "+GRN+"help"+NOR+" "+WHT+" to get more command info. \n "+NOR);
        loginuser->move_object(START_ROOM);
    debug_message(ctime() + " " + query_ip_number(loginuser) + " " + START_ROOM);
    loginuser->look_room();
}

void logon()
{
    color_cat(WELCOME);
    write("Please enter your login name (first-time ant please choose your own, purely English letters):");
    input_to("setup");
}

void net_dead()
{
    debug_message(ctime() + " net_dead " + query_ip_number());
    destruct();
}
