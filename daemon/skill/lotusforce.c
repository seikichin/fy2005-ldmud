// lotusforce.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","莲华心法");
	set("type","force");
	set("usage/force",1);
	set("skill_class","bonze");
	set("effective_level",120);
	set("difficulty",400);
}


int valid_learn(object me){
	if(({int})me->query_skill("buddhism",1) < ({int})me->query_skill("lotusforce",1)){
		return notify_fail("你的大乘佛法修为不够，无法领会更高深的莲华心法。\n");
	}
	return 1;
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int /*num,*/ hit_damage, amount;
	
	if (damage <=0)	return 0;	
	if( me->query_temp("pfm/xg_preservation")<=0)
		return 0;
	
	me->add_temp("pfm/xg_preservation",-1);
	
	data["msg"] = CYN"$n"NOR+CYN"的身畔清风荡溢，$N"NOR+CYN"一阵踯躅。\n"NOR;
	
	hit_damage = me->query_skill("buddhism",1)*10;	
	if (ob->query_hate(me)>0)
		ob->add_hate(me,-hit_damage);
	if ((amount = ob->query_hate(me))<0)
		ob->add_hate(me, -amount);	// 0
				
	if (me->query_temp("pfm/xg_preservation") < 1) {
			ANNIE_D->debuff(me, "xg-detaunt");
	}	
	return data;	
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}