// query_snooping.c
int main(object me, string arg)
{
    object snooper, snoopee;

    if (!arg)
    {
        cecho("Command syntax query_snooping snooper");
    }
    else
    {
        if (!objectp(snooper = find_player(arg)))
        {
            cecho("Couldn't find player " + arg + ". No info provided.");
        }
        else if (objectp(snoopee = query_snooping(snooper)))
        {
            printf("Player %O is snooping %O .\n", snooper, snoopee);
        }
        else
        {
            cecho("Player " + arg + " is not snooping anyone.");
        }
    }

    return 1;
}
