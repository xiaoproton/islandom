// 0,0,0.c
inherit DBASE;

string look_shiban();

void create()
{
    set("short", "传送门出口-海水湾");
    set("long", @LONG
    海水湾很浅, 海水只没到你的腰腹。东北西三面都是嶙峋的海水冲刷的岩石峭壁, 岩石上也没有任何植物的样子。南面则是灰蓝色的大海。
    没有云也没有太阳的纯蓝天空昭示着这里已经不是地球了, 而是一个异次元空间碎片。如果想回到地球, 似乎只需要下潜水下 (输入quit指令) 就可以。
    海水湾中间是一块突起露出水面的岩石，岩石上有块简陋不规则的石板(shiban)和一些棕灰色的织物。
    东面的岩石比较平缓, 似乎可以走上去。
LONG );
    set("exits", ([
        "up":__DIR__ "0,0,1",
    ]));
    set("items", ([
        "shiban" : (: look_shiban :),
    ]));
}

void init()
{

    add_action(function(string arg) {
        object me = this_player();
        me->msp_oob("!!MUSIC(ocean-waves.mp3 L=1 V=100 U=http://islandom.space/music/)");
        return 1;
        //return me->move("/world/area");
    }, ({"listen", "ting"}));

}

string look_shiban()
{
    object me = this_player();
    return "一块就地取材的不规则形状的岩石板, 上面有似乎是用砖红色的石头草草刻画出的向东的箭头, 还有个隐隐约约的听(listen)字？";
}
