int main(object me, string arg)
{
    if(classp(me))
    {
        me->save();
    }
    say("Ant " + (me->short()||geteuid(me)) + " has returned to reality. \n");
    destruct(me);

    return 1;
}
