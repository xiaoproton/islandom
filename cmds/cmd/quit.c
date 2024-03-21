int main(object me, string arg)
{
    if(classp(me))
    {
        me->save();
    }
    say("玩家(" + geteuid(me) + ")退出了游戏。\n");
    destruct(me);

    return 1;
}
