/*****************************************************************************
Copyright: 2021, Mud.Ren
File name: monster_d.c
Description: 游戏怪物守护进程
Author: xuefeng@mud.ren
Version: v1.0
*****************************************************************************/

nosave mixed mob_info = ({
    ({"fly", "mini fly", 11,1}),
    ({"worm", "earth worm", 23,2}),
    ({"termite", "fire termite", 34,3}),
    ({"beetle", "golden beetle", 45,4}),
    ({"cricket", "grass cricket", 67,5}),
    ({"butterfly", "finger butterfly", 87,6}),
    ({"frog", "tree frog", 113,7}),
    ({"snake", "brown snake", 157,8}),
    ({"rat", "cave rat", 201,9}),
    ({"cat", "mountain cat", 298,10}),
});

// 超出范围则随机返回
int limit(int index)
{
    if (index < 1 || index >= sizeof(mob_info))
        index = 1 + random(sizeof(mob_info) - 1);
    return index;
}

mixed info(int index)
{
    index = limit(index);
    return mob_info[index];
}
