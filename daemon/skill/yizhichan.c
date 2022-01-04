//mimicat@fy4
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","一指禅");
	set("type","unarmed");
	set("skill_class","shaolin");
	set("effective_level",210);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",1);
	
	set("parry_msg",			({
			"然而$n轮指虚点，锐利的指风将$N逼退。\n",
			"$n身子一晃之间，已抢到$N对面，虚托一掌，一指点向$N肋下迫得$N闪身后退 。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"然而$n轮指虚点，锐利的指风将$N逼退。\n",
			"$n身子一晃之间，已抢到$N对面，虚托一掌，一指点向$N肋下迫得$N闪身后退 。\n",
			})
	);
	action = ({
			([      "action":               
			"$N斜挥食指，急点两下，隐隐然有一股内力发出击向$n$l ",
			        "dodge":                90,
			        "parry":                150,
			        "force":                100,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
			([      "action":               
			"$N一指点出，大开大阖，气派宏伟，以石破天惊、风雨大至之势刺向$n$l ",
			        "dodge":                140,
			        "parry":                210,
			        "force":                190,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
			([      "action":               
			"只见$N弓步前冲，右手乘势单指直点，激起的气流发出“嗤嗤”的响声 ",
			        "dodge":                230,
			        "parry":                170,
			        "force":                220,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
			([      "action":               
			"$N伸指向前一捺，一股凌厉的指力射将过去，点向$n$l ",
			        "dodge":                380,
			        "parry":                360,
			        "force":                390,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
	});
}

int valid_learn(object me) {
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if(({string})me->query("class") != "shaolin" ) 
		return notify_fail("一指禅是只有少林高僧才能练的武功。\n");
	
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    
	int chance, damage;
	if( !userp(victim) ) {
		victim->add_hate(me, me->query_skill("zen",1)*3);
    }
	chance = 30 + F_ABILITY->check_ability(me, "3_yzc_add", 3) * 2;
	if ( random (100) < chance ) {
		damage = COMBAT_D->magic_modifier(me, victim, "sen", damage_bonus/3+random(damage_bonus/2));     
		victim->receive_damage("sen",damage, me);
		return HIB"$n只觉心口刺痛，无形间已被$N气劲所伤！\n"NOR;
	}
	return 0;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
