// hi.c
int main(object me, string arg)
{
    object ob = find_living(arg);
    msg("hello world", me, arg, ob);

    return 1;
}
