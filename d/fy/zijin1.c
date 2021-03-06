// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"紫禁之巅"NOR);
        set("long","月圆之夜，紫禁之巅！！据说当世两大绝世剑客，『白云城主』叶孤城与『剑神』\n"
"西门吹雪便要在此处决出这天下第一剑客！但问当世天下的武林高手何人不以在此决\n"
"战为毕生荣耀？！\n"
""
        );
    set("exits", ([ 
  		"east" : __DIR__"zijin2",
  		"southeast" : __DIR__"zijin4",
  		"south" : __DIR__"zijin3",
		"northwest" : __DIR__"zijin_n",
	]));
	set("viewer", ({ __DIR__"zijin_e", __DIR__"zijin_w",__DIR__"zijin_s", __DIR__"zijin_n"
		}) );
	set("no_death_penalty",1);
	
    set("outdoors", "fengyun");
	set("coor/x",150);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}

int valid_leave(object ob, string dir){
	if(dir == "northwest" && ob->is_fighting()){
		return notify_fail(HIY"你还在决战中，不可以退出。\n"NOR);
	}
	return 1;
}
