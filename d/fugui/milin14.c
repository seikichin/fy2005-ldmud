#include <ansi.h>
inherit ROOM;
#include "milin.h"

void create()
{
	set("short", HIR"密林"NOR);

	set("long","这是一片密林，周围树木参天而立，遮云蔽日，四周昏昏暗暗，间杂着一些说\n"
"不出名字的红色野花，但见落叶铺地，踩上去沙沙做响，你高一脚低一脚地向前摸\n"
"索，隐隐有些担心，别该是迷路了吧。\n");

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","huo");
	set("exits",([
		"east":__DIR__"milin15",
		"south":__DIR__"milin19",
		"west":__DIR__"milin13",
		"north":__DIR__"milin9",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
