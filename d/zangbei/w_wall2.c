inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "西寨墙");
        set("long","寨墙是照箭楼的格式修筑的，一、二两层都有箭眼，三层只有一半墙壁，从上\n"
"半段也可露出头来向外射箭。若是有人来攻，寨里的人站在墙上向下射箭。居高临\n"
"下，十分得手。寨墙外面是茂密的森林，寨墙里面可以看到一个大院，院子的四周\n"
"有几间瓦房。\n"
""
        );
        set("exits", ([ 
		"southwest" : __DIR__"w_wall3",
		"east":	__DIR__"w_wall1",
	]));
        set("objects", ([
        	__DIR__"npc/archer":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1580);
        set("coor/y",600);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}

