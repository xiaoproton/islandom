// 0,0,1.c
inherit DBASE;


void create()
{
    set("short", "海水湾岩石上");
    set("long", @LONG
    这里比刚从传送门出来的那个海水湾地势略高。
    如果不穿鞋的话站在岩石上会很搁脚。
    从这里能看到仙女岛的部分陆地，基本除了岩石就是沙滩。
    陆地上没有任何植物，连草都没有。
    因为没有雨，这里也没有河流。
LONG );
    set("exits", ([
        "down":__DIR__ "0,0,0",
    ]));
}

void init()
{


}
