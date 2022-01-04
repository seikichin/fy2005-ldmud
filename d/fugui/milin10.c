#include <ansi.h>
inherit ROOM;
#include "milin.h"

void create()
{
	set("short", YEL"密林"NOR);

	set("long","这是一片密林，周围树木参天而立，遮云蔽日，四周昏昏暗暗，间杂着一些说\n"
"不出名字的黄色野花，但见落叶铺地，踩上去沙沙做响，你高一脚低一脚地向前摸\n"
"索，隐隐有些担心，别该是迷路了吧。\n");

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","tu");
	set("exits",([
		"east":__DIR__"milin22",
		"south":__DIR__"milin9",
		"west":__DIR__"milin15",
		"north":__DIR__"milin5",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
