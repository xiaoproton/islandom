/*****************************************************************************
Copyright: 2021, Mud.Ren
File name: monster_d.c
Description: 游戏怪物守护进程
Author: xuefeng@mud.ren
Version: v1.0
*****************************************************************************/

nosave mixed mob_info = ({
    ({"red", "Red Ant", 2,0}),
    ({"fire", "Fire Ant", 2,0}),
    ({"black", "Black Ant", 3,0}),
    ({"brown", "Brown Ant", 3,0}),
    ({"white", "White Ant", 4,0}),
    ({"sugar", "Sugar Ant", 4,0}),
    ({"big", "Big Ant", 6,1}),
    ({"fighter", "Fighter Ant", 7,1}),
    ({"power", "Power Ant", 8,1}),
    ({"mountain", "Mountain Ant", 9,1}),
    /*
    ({"fly", "Mini Fly", 11,1}),
    ({"worm", "Earth Worm", 23,2}),
    ({"termite", "Gray Termite", 34,3}),
    ({"beetle", "Golden Beetle", 45,4}),
    ({"cricket", "Grass Cricket", 67,5}),
    ({"butterfly", "Ghost Butterfly", 87,6}),
    ({"frog", "Tree Frog", 113,7}),
    ({"snake", "Brown Snake", 157,8}),
    ({"rat", "Field Rat", 201,9}),
    ({"cat", "Mountain Cat", 298,10}),
    */
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
