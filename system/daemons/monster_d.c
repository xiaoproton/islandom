/*****************************************************************************
Copyright: 2021, Mud.Ren
File name: monster_d.c
Description: 游戏怪物守护进程
Author: xuefeng@mud.ren
Version: v1.0
*****************************************************************************/
/*
 * ID, Name, HP, 攻, 防, 速, EXP, Gold
 */
nosave mixed mob_info = ({
    ({"mob", "common slug", 11}),
    ({"mob1", "earth worm", 23}),
    ({"mob2", "fire ant", 34}),
    ({"mob3", "golden beetle", 45}),
    ({"mob4", "grass cricket", 67}),
    ({"mob5", "finger butterfly", 87}),
    ({"mob6", "tree frog", 113}),
    ({"mob7", "brown snake", 157}),
    ({"mob8", "cave rat", 201}),
    ({"mob9", "mountain cat", 298}),
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
