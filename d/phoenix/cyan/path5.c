// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "山道");
    set("long","这里的山道与其叫山道，倒不如叫做山隙更恰当些：道路仅有肩宽，左右\n"
"都是坚硬的花岩，惟有一丝微弱的光芒自头顶的石缝中漏下。借着微光，你隐\n"
"可看见窄缝中洒满了凌乱而且锋利的碎石，节节爬高，不知通向何方。\n"
""
NOR
        );
	set("objects", ([
	__DIR__"obj/cliff":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westdown" : __DIR__"forest3",
  		"eastup" : __DIR__"peak1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (!random(3))
	{
		tell_object(me,CYN"你在狭窄的山缝中艰难前行。\n"NOR);
		me->perform_busy(1);
	}
	else if (!random(3))
	{
		tell_object(me,CYN"你努力挤过一处狭窄的山路，不小心踩到锋利的碎石，痛彻心扉。\n"NOR);
		me->receive_wound("kee",20);
		me->set_temp("last_damage_from","在山道中碰个头破血流，力竭而亡。");
	}
	return ::valid_leave(who,dir);
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


