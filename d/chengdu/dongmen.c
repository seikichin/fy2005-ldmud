// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "东门");
        set("long","东门\n"
""
        );
	set("exits",([
  		"west" : __DIR__"dongdajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}