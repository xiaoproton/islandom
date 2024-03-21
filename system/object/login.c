/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: login_ob.c
Description: 玩家登录连线对象
Author: xuefeng
Version: v1.0
Date: 2019-04-18
*****************************************************************************/
#define WELCOME "/system/etc/motd"
object loginuser;

void setup(string arg)
{

    if (!arg || arg == "")
    {
        write("英文名不能为空，请重新输入：");
        input_to("setup");
    }
    else
    {
        // log
        loginuser = new(USER_OB, arg);
        debug_message(ctime() + " " + query_ip_number(checkuser) + " " + arg);
        if(loginuser->load(arg))
        {
            //existing
            write("请输入密码：");
            input_to("password");
        }else
        {
            //new
            write("请输入中文名【建议取用现实风格的中文单姓复姓或单名复名（例如肖莉莉），而不是冗长的网名（你家的重金属），不超过四个字的常用西人音译名（例如夏洛特）也可以。】：");
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
        if( arg==loginuser->query("password",1) )
        {
            cecho("密码正确。");
        }else
        {
            notify_fail("密码错误！请重新输入：");
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
        write("请选择性别: 输入m选择男性, f选择女性, 默认为女性因为在岛上只有女性才能修行灵力增强战力：");
        input_to("setgender");
    }
}

void setgender(string arg)
{

    if (!arg || arg == "")
    {
        loginuser->set("gender", "女");
    }
    else if (|| arg == "f" || arg == "F" || arg == "female" || arg == "Female")
    {
        loginuser->set("gender", "女");
    }
    else if (|| arg == "m" || arg == "M" || arg == "male" || arg == "Male")
    {
        loginuser->set("gender", "男");
    }
    else
    {
        loginuser->set("gender", "女");
    }
    write("最后一步, 请设定密码 (用于下次登录, 不用很复杂, 4-8位数字字母即可): ");
    input_to("setpassword");
}

void setpassword(string arg)
{
    object me;
    if (!arg || arg == "")
    {
        write("密码不能为空，请重新输入：");
        input_to("setpassword");
    }
    else
    {
        loginuser->set("password", arg);
        loginuser->save();
        write("恭喜！注册完成！");
        //use the user
        me = this_object();
        exec(loginuser, me);
        destruct(me);
    }
}

void logon()
{
    color_cat(WELCOME);
    write("请输入你的英文名字(登录用户名，其他旅行者可见，第一次到来的旅行者请直接输入要创建的英文名）：");
    input_to("setup");
}

void net_dead()
{
    debug_message(ctime() + " net_dead " + query_ip_number());
    destruct();
}
