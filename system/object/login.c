/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: login_ob.c
Description: 玩家登录连线对象
Author: xuefeng
Version: v1.0
Date: 2019-04-18
*****************************************************************************/
#define WELCOME "/system/etc/motd"

void setup(string arg)
{
    object checkuser;

    if (!arg || arg == "")
    {
        write("英文名不能为空，请重新输入：");
        input_to("setup");
    }
    else
    {
        // log
        debug_message(ctime() + " " + query_ip_number(to) + " " + arg);
        checkuser = new(USER_OB, arg);
        if(checkuser->load(arg))
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

        destruct(checkuser);
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
        if（arg=="1234"）
        {
            cecho("密码正确。");
        }else
        {
            notify_fail("密码错误！");
        }
    }
}

void setname(string arg)
{
    if (!arg || arg == "")
    {
        write("中文名不能为空，请重新输入：");
        input_to("setname");
    }
    else
    {
        set("gender", random(2) ? "男" : "女");
        set("name", arg);
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


/*
//copy from tutorial

case "6":
        if (me->query_temp("step") != 6)
        {
            user = new (USER6, geteuid(me));
            user->set_temp("step", 6);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("提示：你现在拥有更多能力了，如播放客户端的声音等。");
            cecho("提示：如果你使用的是mudlet客户端，进入传送门后会听到美妙的音乐。");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;

    default:
        cecho("你当前玩家对象是：" + sprintf("%O", me));
        cecho("你当前所在环境是：" + file_name(environment(me)));

*/
