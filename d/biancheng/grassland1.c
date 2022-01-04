inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大道");
        set("long","碧天，黄沙。黄沙连着天，天连着黄沙。远远望过去，一面白色的大旗正在风\n"
"沙中飞卷。大旗似已远在天边。万马堂似也远在天边！无边无际的荒原，路是马蹄\n"
"踏出来的，漫长、笔直，笔直通向那面大旗。旗下就是万马堂。\n"
""
        );
        set("exits", ([ 
		"south" : __DIR__"nstreet4",
		"north" : __DIR__"grassland1a",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",50);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
