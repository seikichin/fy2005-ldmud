// Room: /d/oldpine/cliffside.c

inherit ROOM;

void create()
{
        set("short", "林间....不....悬崖边");
        set("long","你现在正站在一个松树林间的小空地上，你的北边、东边、南边都是茂密的松\n"
"树，唯独西边是个悬崖，当你探头一看，立刻不由自主地倒抽一口凉气，在这里可\n"
"得千万小心，一不小心跌了下去肯定是粉身碎骨。\n"
""
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pine2",
  "north" : __DIR__"pine1",
  "east" : __DIR__"pine1",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "你定下心神一看，其实这个悬崖没有想像中那麽恐怖，也许还\n"
"可以从这里爬下山涧，只是这世界上大概没有这种白痴愿意干\n"
"这种傻事吧。\n"
"",
]));
        set("outdoors", "oldpine");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",15);
	setup();
        replace_program(ROOM);
}
