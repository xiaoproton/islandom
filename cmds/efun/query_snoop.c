// query_snoop.c
int main(object me, string arg)
{
    object snooper, snoopee;

    if (!arg)
    {
        cecho("Commanf syntax: query_snoop snoopee");
    }
    else
    {
        if (!objectp(snoopee = find_player(arg)))
        {
            cecho("COuldn't find player " + arg + ". No info provided.");
        }
        else if (objectp(snooper = query_snoop(snoopee)))
        {
            printf("Player %O is being snooped by %O . \n", snoopee, snooper);
        }
        else
        {
            cecho("Player " + arg + " is not being snooped by anyone. ");
        }
    }
    return 1;
}
