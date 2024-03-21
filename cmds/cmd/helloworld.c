// helloworld.c
int main(object me, string arg)
{
    object ob = find_living(arg);
    cecho("hello world！\n")；
    say("hello world! "+arg+"\n");
    msg("emote","hello world!");
    notify_fail("hello world!");

    return 1;
}
