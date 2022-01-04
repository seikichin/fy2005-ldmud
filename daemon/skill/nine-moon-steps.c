// nine-moon-steps.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","九阴身法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("skill_class","shenshui");
	set("effective_level",150);
	set("practice_limit",100);
	set("difficulty",200);
	set("dodge_msg", ({
		"$n一招「阴差阳错」轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「阴风拂面」早已避在七尺之外。\n",
		"$n使出「阴动阳随」，轻轻松松地闪过。\n",
		"$n左足一点，一招「阴气冲天」腾空而起，避了开去。\n",
		"可是$n使一招「阴阳交错」，身子轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「阴鬼叛阎」轻轻闪过。\n",
		"但是$n一招「阴气森森」使出，早已绕到$N身後！\n"
	}) );
}

int valid_learn(object me)
{
        if( ({string})me->query("gender") != "女性" )
        	return notify_fail("九阴身法是只有女子才能练的武功。\n");
	if (me->query_skill("nine-moon-steps",1)>= me->query_skill("nine-moon-force",1)){
			return notify_fail("你的九阴心经火候不够。\n");
	}	
	return ::valid_learn(me);
}


//	Let chaos-steps add to nine-moon-steps.

int effective_level(object me)
{
	
	int skill,n;
	
	if (me) {
/*		skill = me->query("pfm/chaos-9moon");
		if (skill == 20 || skill == 10 || skill == 30)
			return 150 + skill;	
		else 
			return 150;*/
		skill = me->query_skill("chaos-steps",1);
		if (skill >= 150)	return 180;
		if (skill >= 100)	return 170;
		if (skill >= 50)	return 160;
		return 150;	
	}
	return 180;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}

