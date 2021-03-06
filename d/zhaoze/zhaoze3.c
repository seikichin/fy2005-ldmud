// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit __DIR__"bush_base.c";

void create()
{
	set("short", "火沼死域");
	set("long","这里密布的荆棘挂满倒刺，挡在通往沼泽深处的方向。低矮的小树丛挡住视线，\n"
"使人辨不清方向。地下布满腐烂的枯叶，松松软软的。偶尔有一两个气泡从地上的\n"
"积水下涌出，带出令人作呕的刺鼻气味。\n"
""
	);
	set("exits", ([ 
  "north" : __DIR__"zhaoze2",
]));
        set("objects", ([
                __DIR__"npc/monster1" : 2,
       	]) );

        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"

        ]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
        set("route","west");
        set("route_room",__DIR__"zhaoze4");
	set("coor/x",1010);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
