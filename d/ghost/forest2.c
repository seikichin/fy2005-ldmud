#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "原始丛林");
	set("long","无边无际的丛林中一片黑暗，就是再烈的日光也穿不透那密密的树叶，黑暗中\n"
"充满了各式各样的危险，每一种都可以致命。若是在丛林中迷失了方向，饥渴就足\n"
"以致命。如果没人指引的话，生还的可能性是微乎其微的。\n"
""
	);
	set("exits", ([
		"north" : __DIR__"forest5",
		"south" : __DIR__"forest7",
		"east" : __DIR__"forest3",
		"west" : __DIR__"forest6",
	]));
	set("outdoors", "ghost");
	set("coor/x",-71);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void reset()
{
	::reset();
	set("exits", ([
		"north" : __DIR__"forest5",
		"south" : __DIR__"forest7",
		"east" : __DIR__"forest3",
		"west" : __DIR__"forest6",
	]));
}