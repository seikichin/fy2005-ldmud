// 冰镜七诀 - chillblade.c 
// annie 07.2003
// dancing_faery@hotmail.com
// desc: 星野变暗月式.改

#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","冰镜七诀");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",140);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","moon");
	set("parry_msg", ({
		"$n左手捏诀，右手$v骤展，破一缕萧萧风寒而出，架住$N的攻势。\n",
		})
	);
	set("unarmed_parry_msg", ({
		"$n左手捏诀，右手$v骤展，破一缕萧萧风寒而出，架住$N的攻势。\n",
		})
	);
	action = ({
	([	"action":		"$N抽刀旋舞，一招「暮云收尽溢清寒」洒出银芒一片，如月光般流向$n",
		"dodge":		50,
		"damage":		160,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一挥手中$w，一式「昆仑烟树生愁色」，刀光如月光般轻柔的洒向$n",
		"dodge":		120,
		"damage":		180,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「十轮霜影转庭梧」，刀影化作一轮圆弧，在月色下飘向$n",
		"dodge":		180,
		"damage":		120,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N轻挥$w，秋风漫拂而过，这一刀「中天夜久高明月」似是有无的落向$n",
		"dodge":		160,
		"damage":		160,
		"damage_type":	"割伤"
	]),
	});
}

int valid_learn(object me)
{
	if( !::valid_learn(me) ) {
		return 0;
	}
	if( me->query_skill("snowforce", 1) < me->query_skill("chillblade",1)-20 ) {
		return notify_fail("冷雪心经修为未到，强练冰镜七诀有害无益。\n");
	}
	return 1;
}

int basic_armor(object victim){
	
	int armor, eff_ness, absorb_vic;
	string absorb_skill;
	if( victim->query_skill("iron-cloth") ) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if( absorb_skill ) {
			if( !(eff_ness = SKILL_D(absorb_skill)->ic_effect()) ) {
				eff_ness = 100;
			}
			absorb_vic = victim->query_skill("iron-cloth",1)/2 + victim->query_skill(absorb_skill)*eff_ness/200 + victim->query_temp("apply/iron-cloth");
		} else {
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1)/2 + victim->query_temp("apply/iron-cloth");
		}
	} else {
		absorb_vic = victim->query_temp("apply/iron-cloth");
	}
	return absorb_vic;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int skill, damage, mark, i, *hits, num, n;
	object weapon;

	weapon = me->query_temp("weapon");
	if( !weapon->query("ice_blade") ) {
		return 0;
	}
	if( userp(me) && me->query("class") != "moon" ) {
		return 0;
	}

	if( !userp(me) ) {
		// NPC 的 binglunyingjing is just a fake buff, add 0 damage.
		if( !me->query_temp("annie/chillblade_extradamage") ) {
			me->set_temp("annie/chillblade_extradamage",to_int(pow(to_float(me->query("combat_exp")),0.40)));
		}
	}
	// Extra damage here.
	if( !me->query_temp("annie/chillblade_extradamage") ) {
		return 0;
	}
	if( ANNIE_D->check_buff(me,"enchantweapon") > 0 || !userp(me) ) {
		damage = me->query_temp("annie/chillblade_extradamage");
		damage = damage - victim->query_temp("apply/armor");
		if( damage < 0 ) {
			return 0;
		}
		damage = COMBAT_D->magic_modifier(me,victim,"sen",damage);
		if( me->query_skill("chillblade",1) >= 190 && me->query_skill("stormdance",1) >= 130 ) {
				n = 2;
		} else {
			n = 1;
		}
		hits = me->query_temp("marks/shine_hits");
		if( !hits ) {
			hits = ({});
		}
		for( i = 0;i < sizeof(hits); i++ ) {
			if( hits[i]+30 < time() ) {
				hits -= ({ hits[i] });
			}
		}
		hits -= ({ 0 });
		me->set_temp("marks/shine_hits",hits);
		num = sizeof(hits);
		if( num > 10*n ) {
			num = 10*n; // capped +damage to 50%
		}
		damage += COMBAT_D->magic_modifier(me, victim, "sen", damage*n*num/20);
		victim->receive_damage("sen", damage, me);
		mark = 1;
		COMBAT_D->win_lose_check(me, victim, damage);
	}

	// Extra busy here.
/*	skill = me->query_skill("chillblade",1);
	if (!userp(me))
		skill += 100;
	if (random(skill) > 100 && random(me->query("force"))>random(victim->query("max_force")))
	{
		if (userp(victim))
			victim->perform_busy(random(weapon->query("ice_blade"))+1);	// 1 | 2*
		else
			victim->perform_busy(1);
		mark=1;
	}*/

	if( mark == 1 ) {
		return WHT+weapon->name()+WHT"上传来丝丝寒气，直透进$n"NOR+WHT"骨髓．．\n"NOR;
	} else {
		return 0;
	}
}


int effective_level(object me)
{
	int skill, add;
	if( me && me->query_temp("annie/chillblade_skillup") ) {
		skill = me->query_temp("annie/chillblade_skillup");
		add = F_ABILITY->check_ability(me,"chillblade_add");
		if( skill >= 190 ) {
			return (190 + add);
		}
		if( skill >= 170 ) {
			return (180 + add);
		}
		if( skill >= 150) {
			return (170 + add);
		}
		if( skill >= 120 ) {
			return (160 + add);
		}
	}
	return 140 + add;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("chillblade", 1);
		if( skill < 190 ) {
			return 200;
		} else {
			return 300;
		}
	}
	return 200;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
