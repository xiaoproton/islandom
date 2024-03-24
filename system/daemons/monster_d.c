/*****************************************************************************
Copyright: 2021, Mud.Ren
File name: monster_d.c
Description: 游戏怪物守护进程
Author: xuefeng@mud.ren
Version: v1.0
*****************************************************************************/

nosave mixed mob_info = ({

    ({"brown", "Brown Ant", 2,0}),
    ({"fire", "Fire Ant", 3,0}),
    ({"wood", "Wood Ant", 4,0}),
    ({"sugar", "Sugar Ant", 6,0}),
    ({"bull", "Bull Ant", 9,1}),
    ({"fly", "Mini Fly", 11,1}),
    ({"worm", "Earth Worm", 23,2}),
    ({"termite", "Gray Termite", 34,3}),

    ({"beetle", "Golden Beetle", 45,4}),
    ({"cricket", "Grass Cricket", 67,5}),
    ({"butterfly", "Ghost Butterfly", 87,6}),
    ({"frog", "Beach Frog", 113,7}),
    ({"snake", "Sand Snake", 157,8}),
    ({"crab", "Hermit Crab", 201,9}),
    ({"turtle", "Baby Turtle", 298,10}),

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
