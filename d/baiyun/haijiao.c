//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIB"海角"NOR);
    set("long","海是什么颜色？\n"
"    蓝色。\n"
"    那你的心是什么颜色？\n"
"    也是蓝色。\n"
"    为什么？\n"
"    因为那里只有悲伤。\n"
);
    set("exits", 
      ([ 
	"west" : __DIR__"huangsha1",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/meiyinxue" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
