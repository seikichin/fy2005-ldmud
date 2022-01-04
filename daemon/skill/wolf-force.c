#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","天狼心法");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","wolfmount");
}

/*		in combat_d
mixed hit_ob(object me,object victim,int damage_bonus)
{
	int extra, dream;
	object weapon;
	string skill;
	
	if (damage_bonus < 1)	return 0;
	if (!extra = me->query_temp("rabie"))	return 0;
	
	if (ANNIE_D->check_buff(me,"bloodthirsty"))
		damage_bonus = damage_bonus * 2;
	
	damage_bonus = damage_bonus * (20 + F_ABILITY->check_ability(me,"shigu_add")*2)/100; 
	
	damage_bonus = COMBAT_D->magic_modifier(me, me, "kee", damage_bonus);
		
	me->receive_fulling("kee",damage_bonus,me);
	return;
}*/

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int /*num,*/ hit_damage, amount;
	
	if (damage <=0)	return 0;	
	if( me->query_temp("pfm/wm_preservation")<=0)
		return 0;
	
	me->add_temp("pfm/wm_preservation",-1);
	
	data["msg"] = WHT"$n的身子往下一伏，似乎短小了数分。\n"NOR;
	
	hit_damage = 100 + me->query_skill("hammer")*3;	
	if (ob->query_hate(me)>0)
		ob->add_hate(me,-hit_damage);
	if ((amount = ob->query_hate(me))<0)
		ob->add_hate(me, -amount);	// 0
				
	if (me->query_temp("pfm/wm_preservation") < 1) {
			ANNIE_D->debuff(me, "wm-detaunt");
	}	
	return data;	
}



int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}