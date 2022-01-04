//mac's jiaolou3.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","坎角楼");
  set("long","\n"
"这是岱庙围墙四隅的角楼，分别以四卦为名，以求避凶趋吉，楼中有一面大碑，\n"
"碑上书一大字：\n"
"[33m\n"
"				坎\n"
"[32m\n"
);
  	set("exits",([
         	"south":__DIR__"jiaolou1",
         	"east" :__DIR__"wangyue",
        ]));
        set("objects", ([
                __DIR__"npc/gang3" : 1,
       	]) );
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",10);
	setup();
  	replace_program(ROOM);
}
