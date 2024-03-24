#include <ansi.h>
inherit CLEAN_UP;

string duration()
{
    int t, d, h, m, s;
    string time;

    t = uptime();
    s = t % 60;
    t /= 60;
    m = t % 60;
    t /= 60;
    h = t % 24;
    t /= 24;
    d = t;

    if (d)
        time = d + "天";
    else
        time = "";

    if (h)
        time += h + "小时";
    if (m)
        time += m + "分";
    time += s + "秒";

    return time;
}

int main(object me, string arg)
{
    string msg;
    if (arg == "-v")
    {
        write("\nMUD Name: " + MUD_NAME + "\n");
        write("Driver: " + __ARCH__ + "\n");
        write("Driver Ver: " + __VERSION__ + "\n");
        write("Load: " + query_load_average() + "\n");
        write("Memory: " + memory_info() / 1024 / 1024 + "M\n");
        write("Running: " + duration() + "\n");
        write("Online payers: " + sizeof(users()) + "人\n");
        write("Creatures: " + sizeof(livings()) + "位\n");
        write("Objects: " + sizeof(objects()) + "个\n");
    }
    else
    {
        msg = WHT BBLU "\n Mud Name       Running            Address   Port   Online" NOR;
        msg += "\n─────────────────────────────────────────────────────────────\n";
        msg += sprintf(" %-14s%-20s%-11s%-10d%-5d" NOR, MUD_NAME, duration(), "127.0.0.1", __PORT__, sizeof(users()));
        msg += "\n─────────────────────────────────────────────────────────────\n";
        write(msg);
    }

    return 1;
}
