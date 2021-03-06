inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "莽林之中");
        set("long","四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出昼夜。\n"
"四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼嚎随着腥风\n"
"飘至耳际。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dummy4",
  "west" : __DIR__"dummy4",
  "south" : __DIR__"center4",

]));
        set("objects", ([
                __DIR__"npc/tiger" : 1,
                __DIR__"npc/wolf" : 1,
                __DIR__"npc/snake" : 1,
                __DIR__"npc/bear" : 2,
       ]) );
        set("outdoors", "manglin");
	set("coor/x",60);
	set("coor/y",-150);
	set("coor/z",20);
	setup();
replace_program(ROOM);

}
