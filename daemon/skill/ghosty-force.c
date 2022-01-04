
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","无坎真阴");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","ninja");
}

/*
void skill_improved(object me)
{
	int s,diff;
	
	s = me->query_skill("ghosty-force", 1);
	diff = (s-100)/10;
	if(({int})me->query("age_modify") > -diff && diff > 0) {
        tell_object(me, HIG "由於无坎真阴的驻颜奇效，你显得更发年轻了！\n" NOR);
		me->set("age_modify",-diff);
		me->update_age();
	}
}*/

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "浪人的悲哀" )!= 1) 
		return notify_fail("天枫十四郎未答应转授你这门武功。\n");
	if (!({int})me->query("tianfeng/ghosty-force")){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	return 1;
}
*/

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
