#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"长梦坡"NOR);
	set("long","\n"
"\n"
"　　　　╭─︿＿＿︿─╮ \n"
"　　　　│〈=－﹏－=〉│ Ｚｚｚ \n"
"　　　╭═Ｏ════Ｏ═╮ \n"
"　　　│*　*　*　*　*　*│ \n"
"　　　│　*　*　*　*　* │ \n"
"　　　│*　*　*　*　*　*│ \n"
"　　　╰════════╯\n"
"\n"
"　　还在等什么？快躺下来舒舒\n"
"　　服服地睡一觉～\n"
"\n"
""
        );
	set("exits",([
  		"eastdown" : __DIR__"57",
	]) );

	set("objects", ([
	__DIR__"npc/hu" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",70);
	set("coor/z",20);
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
