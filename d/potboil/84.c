#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"三生石"NOR);
	set("long","\n"
"	\n"
"[1;37m　　　　　　╔╕\n"
"　　　　　　║╰╮\n"
"[1;36m　　　　　　║│╰╮\n"
"　　　　　　║││╰╮\n"
"[1;34m　　　　　　║││││\n"
"　　　　　　╚╧╧╧╛\n"
"[2;37;0m\n"
"\n"
"　今生已知前生事， 三生石上留姓氏， \n"
"　不知来生他是谁， 饮汤便忘三生事。\n"
"\n"
""
        );
	set("exits",([
		"westup" : __DIR__"74",
	]) );

	set("objects", ([
	__DIR__"npc/ding" : 1,
					]) );

  	set("coor/x",80);
	set("coor/y",40);
	set("coor/z",-20);
	set("outdoors", "potboil");
	setup();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
