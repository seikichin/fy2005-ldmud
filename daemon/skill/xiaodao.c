// xiaodao.c edit by hippo 2009 sh site
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","孝道");
	set("skill_class","basic");
	set("difficulty",100);
	set("usage/literate",1);
	set("type","knowledge");
	set("effective_level",150);
}	

void skill_improved(object me) {
			int s;
			s = me->query_skill("xiaodao", 1);
		   	if (s == 50 || s == 100 || s == 150 || s == 200) 
	    		tell_object(me,WHT"由于勤学孝道，你的运气调息更顺畅了。\n"NOR);
			return;
}

int valid_learn(object me)
{

	if (me->query_skill("xiaodao",1) >= me->query_skill("theorem",1)*2)
		return notify_fail("你的无有之术火候不够。\n");

	return ::valid_learn(me);
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3])
);
    return 1;
}