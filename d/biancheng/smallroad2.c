inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "陋巷");
        set("long","小巷不算很窄，刮风的时候灰砂满天，下雨的时候泥泞满路，左邻右舍都是贫苦\n"
"人家，流着鼻涕的小孩子整天在巷子里胡闹啼哭打架玩耍，鸡鸭猫狗拉的屎到处都有，\n"
"家家户户的门口都晒着小孩衣服和尿布。\n"
""
        );
        set("exits", ([ 
	"north" : __DIR__"smallroad1",
	"south" : __DIR__"smallroad3",
	"west"	: __DIR__"cabin2",
	]));
        set("objects", ([
        	__DIR__"npc/huwaigua":	1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",-20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
