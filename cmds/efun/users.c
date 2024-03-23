// 列出游戏所有玩家对象
int main(object me, string arg)
{
    //printf("%O\n", users());
    foreach(object u in users())
    {
        write(u->short() + " " + u->appreance()+"\n");
    }

    return 1;
}
