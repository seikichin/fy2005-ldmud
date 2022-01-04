#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山崖上");
        set("long","在独木桥的这一边，过膝的荒草密密遍洒在山头，枯黄与灰绿交织着时季的色\n"
"彩。草丛中隐隐约约有一条窄小的青纹，是曾被人踩倒过的痕迹。道路向着北面延\n"
"伸而去，地势越发低浅。\n"
""
        );
	set("exits",([
  		"northdown" : __DIR__"hole1",
  		"south" : __DIR__"edge",
	]) );
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",200);
	set("outdoors", "bashan");
	setup();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
