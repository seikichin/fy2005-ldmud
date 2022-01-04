inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "客房");
        set("long","娇娇客栈的客房，一套红杉木的家具，一张六尺宽的大床。屋内打扫的干干净\n"
"净，妆台上一个花瓶里插着一束新采的野茶花。走到窗口向外望去，几缕炊烟正从\n"
"近处的农舍上渺渺升起。\n"
""
        );
        set("exits", ([ 
		"down" : __DIR__"jiaojiao1",
	]));
        set("objects", ([
        	__DIR__"obj/vase": 1,
	]) );
	set("coor/x",50);
        set("coor/y",70);
        set("coor/z",10);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
