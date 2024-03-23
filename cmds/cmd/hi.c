// hi.c
int main(object me, string arg)
{
    object ob;
    if (arg &&ob = find_living(arg))
    {
        if (ob == me)
        {
            msg("emote", "$ME emotionally greeting $ME themselves.", me);
        }
        else
        {
            msg("emote", "$ME emotionally greeting $YOU.", me, ob);
        }
    }
    else
    {
        msg("emote", "$ME emotionally greeting everyone.", me);
    }

    return 1;
}
