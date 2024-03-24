inherit OBJECT;

void create()
{

}

int get_new_ant_total()
{
    int num=0;
    num = to_int(query("new_ant_total"));
    return num;
}

int increase_new_ant_total()
{
    int num=0;
    num = to_int(query("new_ant_total"));
    num++;
    set("new_ant_total", num);
    save();
    return num;
}
