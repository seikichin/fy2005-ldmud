// silencer@fy4.com
//打狗棒法共有八诀，

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","打狗棒法");
	set("type","staff");
	set("usage/staff",1);
	set("usage/parry",1);
	set("skill_class","beggar");
	set("effective_level",210);
	set("practice_limit",100);
	set("difficulty",250);
	set("parry_msg", ({
			"$n使出个『缠字诀』，$n有如一根极坚韧的细藤，粘在$N的$w上。\n",
			"$n不避不闪，一招『双龙夺珠』，手中$v直取$N的双目。\n",
			"$n$v疾翻，搭在$w半腰，顺势向外牵引。\n",
			"$n$v缩回，使起『挑字诀』，搭住$w向上甩出。\n",
	})
	);
	set("unarmed_parry_msg", ({
			"$n伸出$v，一招『拨狗朝天』，封住了$N的攻势。\n",
			"$n不避不闪，一招『双龙夺珠』，手中$v直取$N的双目。\n",
			"$n挥出$v，蓦地点向$N的面门。\n",
	})	
	);	
	action = ({
([      "action": "$N使出一招『棒打双犬』，手中$w化作两道青光砸向$n的$l",
        "dodge": 10,
        "parry": 70,
        "damage": 90,
        "damage_type": "刺伤"
]),
([      "action": "$N手中$w左右晃动，倏然中宫直进，径点$n前胸“紫宫穴”",
        "dodge": 20,
        "parry": 100,
        "damage": 120,
        "damage_type": "刺伤"
]),
([      "action": "$N一声怪啸，飘身而进，手中$w暴起，化作漫天棒影，向$n下盘扫去",
        "dodge": 20,
        "parry": 50,
        "damage": 120,
        "damage_type": "刺伤"
]),
([      "action": "$N使出打狗棒法中“沾”“挑”“抹”“拌”诸般法诀，灵蛇也似招招不离$n的要害",
        "dodge": 20,
        "parry": 270,
        "damage": 120,
        "damage_type": "刺伤"
]),
([      "action": "$N提起$w，一招『棒打狗头』，往$n头顶击去，出手狠辣，来势迅猛",
        "dodge": 20,
        "parry": 110,
        "damage": 120,
        "damage_type": "刺伤"
]),
([      "action": "$N使出『拨狗朝天』，$w由下往上向$n撩去",
        "dodge": 120,
        "parry": 70,
        "damage": 180,
        "damage_type": "刺伤"
]),
([      "action": "$N使出『关门打狗』，但见$w化成了一团碧影，猛点$n后心各大要穴",
        "dodge": 120,
        "parry": 300,
        "damage": 150,
        "damage_type": "刺伤"
]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob, weapon;
	int myexp, urexp, skill, chance1, chance2, chance;
	    
	if( me->query("class") != "beggar" ) {
		return 0;
	}
	weapon = me->query_temp("weapon");
	skill = me->query_skill("dagou-stick",1);
	if( !victim->is_busy() && !me->query_temp("marks/pfm_dagou") ) {
		if( skill >= 180 && me->query_skill_mapped("force") == "huntunforce" ) {
			chance1 = F_ABILITY->check_ability(me, "3_pizi_add", 3)/2;
			chance2 = 20;
			if( random(100) < chance1 || ( COMBAT_D->do_busy_attack( me, victim, "dagou-stick/chanzijue", "unarmed", 100, 10) && random(100) < chance2 ) ) {
				message_vision(HIW "\n$N使出缠字诀，手中"+weapon->name()+HIW"有如一根极坚韧的细藤，缠住了$n。\n"NOR, me, victim);
				victim->force_busy(1);
			}
		}
	}

	if( skill >=180 && me->query_skill("begging",1) >= 200 && me->query_skill_mapped("force") == "huntunforce" ) {
		chance = 6 + (F_ABILITY->check_ability(me,"pizi_add")+F_ABILITY->check_ability(me, "3_pizi_add", 3))/2;
	//	tell_object(me,"chance is " + chance + "\n");
		if( chance >16 ) {
			chance = 16;
		}	        
		if( random(100) < chance ) {
			message_vision(HIR"\n$N运起劈字诀，手中"+weapon->name()+HIR"虎虎生风，威猛异常。\n"NOR, me, victim);
			return damage_bonus;
		}
	}
	 
	if( random(damage_bonus) < 250 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "whip" ) {
			if( victim->query_skill_mapped("whip") == "thunderwhip" ) {
				if( me->query_skill("staff") > victim->query_skill("whip") ) {
					switch( random(3) ) {
						case 0:
							message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
							break;
						case 1:
							message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
							break;
						case 2:
							message_vision(HIR "\n因棍鞭法相克，$n逐渐施展不开了！" NOR,me,victim);
							break;
					}
					return random(me->query_skill("staff")) * 2;
				}
			}
		}
	}
	return 0;
}


mixed parry_ob(object victim, object me)
{	
	int skill, my_exp, your_exp;
	string msg;
	mapping buff;

	my_exp = me->query("combat_exp");
	your_exp = victim->query("combat_exp");
	skill = me->query_skill("dagou-stick",1);

	if( !ANNIE_D->check_buff(me, "parryup") && me->query_skill("dagou-stick",1) >= 130 && me->query("class") == "beggar" ) {
		msg=CYN"\n$N"+CYN"使出打狗棒法中的封字诀，但见满天棒影，登时将自己身前数尺之地尽数封住。\n"NOR;
		buff =
		([
			"caster":me,
			"who":me,
			"type":"parryup",
			"att":"bless",
			"name":"打狗棒法·封字诀",
			"buff1":"apply/parry",
			"buff1_c":skill/3,
			"time":20,
			"buff_msg":msg,
		]);
		ANNIE_D->buffup(buff);
		return;
	}

	if( me->is_busy() ) {
		return 0;
	}
	if( victim->query("race") == "野兽" ) {
		return 0;
	}
	if( random(3*my_exp) > your_exp && me->query_skill("dagou-stick",1) >= 170 && me->query("class") == "beggar" && random(2) ) {
		me->set_temp("counter_action", 1);
		me->set_temp("counter_msg", HIY"$N使出打狗棒法转字诀，手中棒儿借机反击。\n"NOR);
		return 0;
	}
	return 1;
}	


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
