int main(object me, string arg)
{
    if(classp(me))
    {
        me->save();
    }
    say("Ant " + geteuid(me) + " returns to reality. \n");
    destruct(me);

    return 1;
}
