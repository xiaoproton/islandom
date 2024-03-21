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
        write("用户名不能为空，请重新输入：");
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
            write("请输入密码：");
            input_to("password");
        }else
        {
            //new
            write("请输入中文名【建议取用现实风格的中文单姓复姓或单名复名（例如肖莉莉），而不是冗长的网名（你家的重金属）; 不超过四个字的常用西人音译名（例如夏洛特）也可以。】：");
            input_to("setname");
        }

    }
}

void password(string arg)
{
    if (!arg || arg == "")
    {
        write("密码不能为空，请重新输入：");
        input_to("password");
    }
    else
    {
        if( arg==loginuser->query("password") )
        {
            cecho("登录成功。");
            this_object()->landing();
        }else
        {
            write("密码错误！请重新输入：");
            input_to("password");
        }
    }
}

void setname(string arg)
{
    debug_message(ctime() + " " + " setname " + arg);

    if (!arg || arg == "")
    {
        write("中文名不能为空，请重新输入：");
        input_to("setname");
    }
    else
    {
        //loginuser->set("gender", random(2) ? "男" : "女");
        loginuser->set("name", arg);
        debug_message(ctime() + " " + query_ip_number(loginuser) + " " + arg);
        write("请选择性别: 输入m选择男性, f选择女性。默认为女性, 因为在岛上只有女性才能修行灵力增强战力: ");
        input_to("setgender");
    }
}

void setgender(string arg)
{

    if (!arg || arg == "")
    {
        loginuser->set("gender", "女");
    }
    else if (arg == "f" || arg == "F" || arg == "female" || arg == "Female")
    {
        loginuser->set("gender", "女");
    }
    else if (arg == "m" || arg == "M" || arg == "male" || arg == "Male")
    {
        loginuser->set("gender", "男");
    }
    else
    {
        loginuser->set("gender", "女");
    }
    write("请设定密码 (用于下次登录, 不用很复杂, 4-8位数字字母即可): ");
    input_to("setpassword");
}

void setpassword(string arg)
{
    if (!arg || arg == "")
    {
        write("密码不能为空，请重新输入：");
        input_to("setpassword");
    }
    else
    {
        loginuser->set("password", arg);
        loginuser->save();
        cecho("恭喜！注册完成！");
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
    write(YEL+"前一秒钟你还在地球上的西太平洋某处, 在工作人员的指示下, 赤身裸体游向那海面下的不可见的传送门...\n"+NOR);
    write(YEL+"眼前一晃，下一秒中你就奇迹般的出现在了"+HBMAG+"仙女岛"+NOR+" "+YEL+"这个异次元碎片空间里。 \n"+NOR);
    write(WHT+"提示: 你可以用键盘输入"+GRN+"look"+NOR+"或"+GRN+"l"+NOR+" "+WHT+"四处看看。或输入"+GRN+"help"++NOR+" "+WHT+"获取更多帮助信息。\n "+NOR);
        loginuser->move_object(START_ROOM);
    debug_message(ctime() + " " + query_ip_number(loginuser) + " " + START_ROOM);
    loginuser->look_room();
}

void logon()
{
    color_cat(WELCOME);
    write("请输入你的英文用户名 (首次到来的旅行者请直接输入要创建的用户名）：");
    input_to("setup");
}

void net_dead()
{
    debug_message(ctime() + " net_dead " + query_ip_number());
    destruct();
}
