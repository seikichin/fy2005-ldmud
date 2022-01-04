// nine-moon-force.c
inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","九阴心经");
	set("type","force");
	set("effective_level",100);
	set("usage/force",1);
	set("skill_class","shenshui");
	set("difficulty",200);
	set("no_refund",({"nine-moon-claw","nine-moon-steps"}));
}
 
mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage,ratio, rec;
	object weapon;
	string msg;
	
/*	if ((ratio=me->query_temp("pfm/9moon_huaxue"))) {		// 化血神功。
		rec = COMBAT_D->magic_modifier(me, victim, "kee", 
			damage_bonus *(ratio + F_ABILITY->check_ability(me,"huaxue_add")*5)/100);
		if (ratio==20) msg =RED"\n$N"NOR RED"但觉全身气血都晃了一晃。\n"NOR;
		else if (ratio=30)	msg = RED"\n$N"NOR RED"心头一颤，气血浮动不止。\n"NOR;
		else 		msg = RED"\n$N"NOR RED"但觉全身气血飞泻而出。\n"NOR;	
		me->receive_fulling("kee",rec, me);
		message_vision(msg, victim);
	}*/
		
	if(!extra=me->query_temp("nine-moon-force_poison")) return ;
	
	damage = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	if (weapon=me->query_temp("weapon")){
		if (weapon->query("skill_type")=="sword" && 
			me->query_skill_mapped("sword") == "nine-moon-sword")
		{	
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			return MAG"$n"NOR MAG"只觉丝丝寒意透骨，似乎有一缕紫云般的雾气从$N"NOR MAG"兵刃上传来。\n"NOR;
		}
		if ((weapon->query("skill_type")=="unarmed" && 
			me->query_skill_mapped("unarmed") == "nine-moon-claw"))
		{	
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			return MAG"一缕紫云般的雾气一闪，$n"NOR MAG"只觉冷厉的阴风如刺如锥般从$N"NOR MAG"指尖传来。\n"NOR;
		}	
			
	} else if (me->query_skill_mapped("unarmed") == "nine-moon-claw")
		{
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			msg=MAG"一缕紫云般的雾气一闪，$n"NOR MAG"只觉冷厉的阴风如刺如锥般从$N"NOR MAG"指尖传来。\n"NOR;
			return msg;
		}
	return 0;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
