inherit ROOM;

void create()
{
	set("short", "废旧驿道");
	set("long","这是条东西走向的废旧驿道，道上行人寥寥，时近深秋，放眼望去，尽是枯树\n"
"败草，朔风肃杀，吹得野草起伏不定，风沙也不时吹进旅人的双眼，也看不清前方\n"
"究竟如何。\n");
	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
                "east" : __DIR__"dengfeng",
	 	"west":__DIR__"xiaodao2"
	]) );

	set("coor/x",-700);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
