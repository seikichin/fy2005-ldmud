inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "院子");
        set("long","一片大的空场，两边是农场的房屋，后面是庄主的宅子，宅子的两翼连接着一\n"
"面高高的园墙，墙后是一排一排的繁茂的白杉。中间是一条宽的直路，顺着这条路\n"
"走过去，便可以进入万马堂的正厅。向远处望，便是无边无际的草场。\n"
""
        );
        set("exits", ([ 
	"north" : __DIR__"hall1",
	"west": __DIR__"stable1",
	"south": __DIR__"yard",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",95);
        set("coor/z",0);
	set("map","zbwest");
        set("end",1);
	setup();
	replace_program(ROOM);
}
