// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "黑暗山洞");
	set("long","这是一个阴森可怖而且黯淡无光的山洞，一走进来，你倒吸了一口凉气，脑中\n"
"一阵晕眩，就什么也想不起来了。\n"
""
	);
	set("exits", ([
		"west" : __FILE__,
        "east" : __DIR__"d7",
        "south" : __FILE__,
		"north" : __FILE__,
	]));
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
