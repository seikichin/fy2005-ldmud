// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "峨眉山");
        set("long","峨眉山\n"
""
        );
	set("exits",([
  		"southwest" : __DIR__"shangshanlu",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}