//Sinny@fengyun 2003 
//All Rights Reserved 
inherit ROOM;
void create()
{
    set("short", "飞仙亭");             set("long","你不知到了什么所在。但见红花绿树间，有亭翼然。一缕流泉自亭畔倒泄而下。\n"
"飞珠溅玉。被夕阳一映更是七彩生光。艳丽不可方物。你骤然到了这个地方。几疑置\n"
"身天上。淡淡的晚风吹来，你不禁有些痴了。许久，方回过神来。亭间有匾：\n"
"                           瑶    空\n"
"                           琴    山\n"
"                           弄    话\n"
"                           巧    雨\n"
);
    set("exits",
      ([
	"northeast" : __DIR__"yuhuage",
	"southup" : __DIR__"dragonplace",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set ("objects",
      ([
	__DIR__"npc/qinxin" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-30);
    set("coor/y",-60);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
