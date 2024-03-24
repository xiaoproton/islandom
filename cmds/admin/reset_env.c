int main(object me, string arg)
{
    object env = environment(me);

    env->reset();

    write(sprintf("reset %O",env));

    return 1;
}
