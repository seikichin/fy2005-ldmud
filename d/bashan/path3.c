#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后山小道");
        set("long","前后都是草丛和树木，左右是非常茂盛的梧桐木，小路两旁长满了各色说不出\n"
"名字的鲜艳的花。荫翳蔽日的梧桐树下，崎岖不平的羊肠小路映着一种森森然的感\n"
"觉。梧桐的枝叶很茂盛，完全遮蔽了你头顶的天空，使路面陷入一片浓重的黑暗，\n"
"许多圆圆的小亮点会忽然在地上成片的出现，又迅速的消失，那是枝叶的缝隙间漏\n"
"下的光线。\n"
""
        );
	set("exits",([
  		"east" : __DIR__"path2",
  		"west" : __DIR__"path4",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-70);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	if (!query("wall"))
	{
    	set("wall",1);
		clone_object(__DIR__"npc/wall")->move(this_object());
	}
}

int valid_leave(object me, string dir)
{
	if (present("wall of blossoms",this_object()) && dir == "west")
		return notify_fail("这个方向的道路被一堵花墙阻挡住了。\n");
	return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
