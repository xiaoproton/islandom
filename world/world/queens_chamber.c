// queens_chamber.c
//inherit DBASE;
inherit ROOM;


void create()
{
    mixed npc = __DIR__ "npc/npc";
    object result;

    set("short", "Queens Chamber");
    set("long", @LONG
    A big chamber for Queen Ant Islandom to live.
    She is more than ten times of your size,
    carrying gene from far-far-away home planet.
    She continues needing food to produce those eggs.
    Eggs need to be moved the Egg Chamber for good tempareture to incubate.
LONG );
    set("exits", ([
        "south":__DIR__ "worker_ant_hall",
    ]));

    result=load_object(npc);
    debug_message(sprintf("load npc %d", objectp(result)));
    debug_message(sprintf("load npc %s", result->query("name")));
    set("objects", ([
        npc:1,
    ]));

    /*
    mapping ob_list, ob;
	string ob_kind;
	int amount;

    foreach(ob_kind, amount in ob_list) {
			if( amount==1 ) {
				if( !objectp(ob[ob_kind]) ) ob[ob_kind] = make_inventory(ob_kind);
			} else {
				for(int i=0; i<amount; i++)
					if( !objectp(ob[ob_kind + " " + i ]) )
						ob[ob_kind + " " + i] = make_inventory(ob_kind);
			}
		}

    */
}

void init()
{


}
