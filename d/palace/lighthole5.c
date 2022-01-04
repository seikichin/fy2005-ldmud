
inherit ROOM;
void create()
{
        set("short", "洞穴");
        set("long","借著手中的光亮，你看清楚了四周的景色。只见怪石林立，道路错综复杂，你\n"
"已经迷失了方向。几只小老鼠在你脚边跑来跑去。在这里，你根本分不清东南西北；\n"
"而东南西北对你来说，也没有任何意义。是生是死，只能听天由命。。\n"
""
        );
        set("exits", ([ 
		"east" : __DIR__"lighthole1",
		"west" : __DIR__"lighthole2",
		"north" : __DIR__"lighthole3",
		"south" : __DIR__"lighthole4",
		"out" : __DIR__"cliff",
	]));
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}
