inherit ROOM;

void create()
{
	set("short", "云雾石径");

	set("long","山中云雾缭绕，小路蜿蜒而上，一丛丛不知名的小花在山风中摇曳，正值花落\n"
"时节，斜斜的石径上落花缤纷。踏着落花，“沙沙”之声在寂静的山谷中似乎格外\n"
"清晰，风中也充满了干燥木叶和百花的芬芳，青天下远山如翠。\n");

	set("type","road");
	set("exits",([
        "southup":__DIR__"fogpath4",
        "eastup":__DIR__"fogpathx",
        "northdown":__DIR__"fogpath2",
	]) );
        set("objects", ([
                __DIR__"obj/dropflower" : 2,
       ]) );
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",10);
       set("outdoors", "wolfmount");

	setup();
	replace_program(ROOM);
}
