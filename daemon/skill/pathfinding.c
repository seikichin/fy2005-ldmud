
inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","天路引归");
	set("type","knowledge");
	set("skill_class","theorem");
	set("usage/theorem",1);
	set("effective_level",100);
	set("difficulty", 30);	
}

/*
int valid_learn(object me)
{

	if (me->query_skill("pathfinding",1) >= me->query_skill("theorem",1))
		return notify_fail("你的无有之术火候不够。\n");

	return ::valid_learn(me);
}*/

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
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


