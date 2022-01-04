#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "红巷");
        set("long","红巷一侧是一排平房，西北最普通，最常见的砖土四合院，住在这里的大多数\n"
"是靠手艺吃饭的，有开小杂货铺的，理发的，打铁的，伐木的，也有的是常年奔波\n"
"于塞外和中原的生意人。\n"
""
        );
        set("exits", ([ 
		"east" : __DIR__"sroad4",
		"west" : __DIR__"sroad2",
		"south": __DIR__"house5",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
