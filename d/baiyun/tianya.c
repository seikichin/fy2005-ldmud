//Sinny@fengyun 2003 
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIC"天涯"NOR);
    set("long","天涯远不远？\n"
"    不远。\n"
"    天涯就在你脚下，\n"
"    在你心中。\n"
);
    set("exits", 
      ([ 
	"east" : __DIR__"huangsha1",
      ]));
    set("objects", 
      ([ 
		__DIR__"npc/nangongpin" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
