inherit ROOM;

void create()
{
	set("short", "山间丛林");

	set("long","这里黑漆漆的，伸出手去几乎看不见自己的手指。脚下磕磕绊绊，也不知道\n"
"会踩到什么东西。看来还是尽快找条出路的好。远处不停的传来阵阵山溪的流淌\n"
"声，似乎在告诉你不远的地方就有你梦想中的世外桃源。\n");
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"shanlin",
		"south":__DIR__"shanlin2",
		"west":__DIR__"shanlin1",
		"north":__DIR__"shanlin4",
	]) );
	set("coor/x",10);
	set("coor/y",170);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
