inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山道");
        set("long","山路更见崎岖，乱石丛中几棵野草顽强地伸出头来。群山似在远处，又似在近\n"
"处，在这孤寂的山谷里，却像哀伤的笛韵，流露出人间侧腓的哀息。沉沉的暮色，\n"
"凄迷的云天中，突然现出一席灯火。\n"
""
        );
        set("exits", ([ 
	"northdown" : __DIR__"road1",
	"northup" : __DIR__"valleyentry",
	]));
        set("objects", ([
        	__DIR__"obj/grass": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("grass", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        	item = clone_object(__DIR__"obj/duancao");
        item->move(con);
        }
}
