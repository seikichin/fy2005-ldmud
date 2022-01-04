// score.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// Last modification:
//  06/27/2001 by Daniel Q. Yu.
// Last modification:
// 02/25/2002 by neon

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
int basic_damage(object me);
int basic_armor (object me);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type, parry_type, dodge_type, wptype, jiebai, word1;
	object weapon;
	int attack_points, dodge_points, parry_points, magic_points;
	int level, task_num, rewarded_task;

	seteuid(getuid(me));
	if( !arg ) {
		ob = me;
	} else if( wizardp(me) ) {
		ob = present(arg, environment(me));
		if( !ob ) {
			ob = find_player(arg);
		}
		if( !ob ) {
			ob = find_living(arg);
		}
		if( !ob ) {
			return notify_fail("你要察看谁的状态？\n");
		}
	} else {
		return notify_fail("你只可以察看自己的状态。\n");
	}

	level = F_LEVEL->get_level(ob->query("combat_exp"));
	task_num = F_LEVEL->level_to_pot(level)/10/50;
	rewarded_task = ob->query("rewarded_task");
	my = ob->query_entire_dbase();
	printf(HIC"≡"HIY"------------------------------------------------------"HIC"≡\n"NOR);
	printf( "   %s\n", ob->short(1) );
	printf(HIC"≡"HIY"------------------------------------------------------"HIC"≡\n"NOR);
	line =  sprintf(" 【力量】%-8s\t【民族】%-10s【杀死人数】 %d（%d） \n",
						display_attr(my["str"], ob->query_str()),(ob->query("national")? ob->query("national") : "无"),
						my["MKS"], my["PKS"]);
	line += sprintf(" 【速度】%-8s\t【性别】%-10s【被杀次数】 %-12d \n",
						display_attr(my["agi"], ob->query_agi()), ob->query("gender"), my["KILLED"]);
	line += sprintf(" 【体质】%-8s\t【年龄】%-10s【杀死天骄】 %-12d \n",
						display_attr(my["con"], ob->query_con()), chinese_number(ob->query("age")),
						sizeof(my["m_killer"]));
	line += sprintf(" 【才智】%-8s\t【门派】%-10s【ＴＡＳＫ】 %-12d \n",
						display_attr(my["int"], ob->query_int()),
						(my["family"]?(my["family"]["family_name"]? my["family"]["family_name"]:"无"):"无")
						+ (my["betrayer"]? sprintf("*%d",my["betrayer"]):""), my["TASK"]);
	line += sprintf(" 【定力】%-8s\t【师父】%-10s【ＴＫ。Ｐ】（%d/%d） \n",
						display_attr(my["cps"], ob->query_cps()),
						(my["family"]?(my["family"]["master_name"]? my["family"]["master_name"]:"无"):"无"),
						rewarded_task, task_num);
	if( !my["marry"] ) {
		line += sprintf(" 【运气】%-8s\t【婚姻】%-10s【ＱＳＴ。】 %-8d（%d）\n",
							display_attr(my["kar"], ob->query_kar()),
							(my["divorced"]?(ob->query("gender") == "女性" ? "寡居":"鳏居"):"未婚")
							+ (my["divorced"]? sprintf("*%d",my["divorced"]):""),
							my["FINISH_QUEST"], my["cont_quest"]);
	} else {
		line += sprintf(" 【运气】%-8s\t【%s】%-10s【ＱＳＴ。】 %-8d（%d） \n",
							display_attr(my["kar"], ob->query_kar()),
							(!ob->query("jiebai"))?(ob->query("gender") == "女性"? "丈夫":"妻子")
							: "结义",
							my["marry_name"],
							my["FINISH_QUEST"],
							my["cont_quest"]);
	}
	wptype = objectp(weapon = ob->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
	skill_type = ob->query_skill_mapped(wptype);
	parry_type = ob->query_skill_mapped("parry");
	if( !stringp(parry_type) ) {
		parry_type = "parry";
	}
	if( wptype == "unarmed" && (parry_type == "parry" || SKILL_D(parry_type)->type()!= "unarmed") && ob->query_skill_mapped("unarmed") ) {
		parry_type = ob->query_skill_mapped("unarmed");
	}
	dodge_type = ob->query_skill_mapped("dodge");
	if( !stringp(dodge_type) ) {
		dodge_type = "dodge";
	}
	attack_points = COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK);
	// Condition modified
	if( ob->is_busy() ) {
		attack_points = 0;
	}
	// Quest buff-atk
	if( ANNIE_D->check_buff(ob,"quest_atk") ) {
		attack_points = attack_points * (100 + ob->query_temp("apply/quest_atk"))/100;
	}
	parry_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY);
	// Quest buff-parry
	if( ANNIE_D->check_buff(ob,"quest_parry") ) {
		parry_points = parry_points * (100 + ob->query_temp("apply/quest_parry"))/100;
	}
	// Condition modified
	if( ob->is_busy() || ANNIE_D->check_buff(ob,"pseudo-busy") ) {
		parry_points = parry_points*2/5;
	}
	dodge_points = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
	if( ob->is_busy() || ANNIE_D->check_buff(ob,"pseudo-busy") ){
		if( ob->query_skill_mapped("dodge") == "stormdance" && ob->query("class") == "moon" ) {
			dodge_points = dodge_points * 3/5;
		} else {
			dodge_points = dodge_points * 2/5;
		}
	}
	magic_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PERCEPTION);
	if( !stringp(skill_type) ) {
		skill_type = wptype;
		line += sprintf(YEL"\n 【攻击：%|12s】 %-14d"WHT"【杀伤】 %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));
	} else {
		line += sprintf(HIG"\n 【攻击：%|12s】 %-14d"WHT"【杀伤】 %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));
	}
	if( SKILL_D(parry_type)->type() == wptype ) {
		line += sprintf(HIG" 【招架：%|12s】 %-14d"WHT"【护甲】 %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	} else {
		line += sprintf(YEL" 【招架：%|12s】 %-14d"WHT"【护甲】 %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	}
	if( dodge_type== "dodge" ) {
		line += sprintf(YEL" 【闪躲：%|12s】 %-14d"WHT"【护法】 %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
	} else {
		line += sprintf(HIG" 【闪躲：%|12s】 %-14d"WHT"【护法】 %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
	}
	if( ob->query("death/half_quest") < 0 ) { 
		if( level < 50 && ob->query("death/time")+86400 < time() ) {
			// 超过24 小时，肯定不能revive,也没有Penalty
			if( ob == me ) {
				// we don't want wiz to accidently do this for others:)
				ob->delete("death/half_quest");
				ob->delete("death/exp_lost");
				ob->set("death/revived",1);
			}
			line+= sprintf(CYN"\n	你的死亡损失在２４小时后自动消失了！\n"NOR);
		} else {
			line += sprintf(CYN"\n距离上次死亡时间已有%d小时%d分钟，会影响大约%d个单人天机任务。\n"NOR,
							(time()-ob->query("death/time"))/3600, ((time()-ob->query("death/time"))%3600)/60,
							-(ob->query("death/half_quest"))/(REWARD_D->quest_reward(F_LEVEL->get_level(me->query("combat_exp"))))
			);
		}
	}
	write(line);
	printf(HIC"≡"HIY"------------------------------------------------------"HIC"≡\n"NOR);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) {
		return sprintf( HIY "%3d /%3d" NOR, value, gift);
	} else if( value < gift ) {
		return sprintf( HIR "%3d /%3d" NOR, value, gift);
	} else {
		return sprintf("%3d /%3d", value, gift);
	}
}

string status_color(int current, int max)
{
	int percent;

	if( max ) {
		percent = current * 100 / max;
	} else {
		percent = 100;
	}
	if( percent > 100 ) {
		return HIC;
	}
	if( percent >= 90 ) {
		return HIG;
	}
	if( percent >= 60 ) {
		return HIY;
	}
	if( percent >= 30 ) {
		return YEL;
	}
	if( percent >= 10 ) {
		return HIR;
	}
	return RED;
}

// Eventually... this should be directly quoted from COMBAT_D.
int basic_damage(object attacker)
{
	int str, damage, force_factor, bounce, att_combat_exp, weapon_damage;
	int d0, d1, d2, d3, d3x, d4, d5, d6, d7, d_race, d_1, d_2, d_3; // Debug message.
	string force_skill, attack_skill, martial_skill;
	object attweapon;
	mixed tmp;
	closure f;

	attweapon = attacker->query_temp("weapon");
	// Strength damage bonus. --- this is the combined effect of str + enforce.
	// if use weapon, effectiveness only 4/5
	str = attacker->query_str();
	if( str <= 130 ) {
		d1 = str*str/10;
	} else {
		d1 = 1690 + (str-130)*13;
	}
	d1 = d1 *3/4; // Weapon or not..damage all reduced by 1/4
	// Let race factor take effect. 
	d_race = d1 /10;
	if( attacker->query("national") == "蒙古族") {
		d1 += d_race;
	}
	if( attacker->query("national") == "满族") {
		d1 -= d_race;
	}
	// Weapon damage consists of weapon_prop/damage + apply_temp/damage.
	d2 = attacker->query_temp("apply/damage") + 2;
	// skill damage -- this is defined in individual skill.
	if( objectp(attweapon) ) {
		attack_skill = attweapon->query("skill_type");
	} else {
		attack_skill = "unarmed";
	}
	if( stringp(martial_skill = attacker->query_skill_mapped(attack_skill)) ) {
		d3 = SKILL_D(martial_skill)->damage_level(attacker);
		d3 = d3 * (d1 + d2) / 1000;
	}
	// Quest_buff
	if( ANNIE_D->check_buff(attacker,"quest_dmg") ) {
		d3x = (d1+d2) * attacker->query_temp("apply/quest_dmg")/100;
	}
	// Let combat exp take effect.. assume against 0 level
	d7 = F_LEVEL->get_level(attacker->query("combat_exp"));
	d7 = d7*5/2;
	// Add damage bonus.
	d_1 = d1 + d2 + d3 + d3x + d7;
//	CHANNEL_D->do_sys_channel("sys", sprintf("%d %d %d %d %d %d\n", d_1, d1, d2, d3, d3x, d7));
	if( ANNIE_D->check_buff(attacker,"damagecurse") < 1 ) {
		d_3 = d_1 *3/4; // normally average = 75% 
	} else {
		if( (attacker->query_temp("buff/"+ANNIE_D->check_buff(attacker,"damagecurse")))["att"] == "curse" ) {
			d_3 = d_1/2; // curse type curse, 50%,-25%
		} else {
			d_3 = d_1; // blessing type damage curse, 100%,+25%
		}
	}
	if( ANNIE_D->check_buff(attacker,"weaken") >= 1 ) {
		d_3-=d_3*attacker->query_temp("buffup/weakened")/100;
	}
	damage = d_3;
	if( damage < 0 ) {
		damage = 0;
	}
	// add a log here	
	if( userp(attacker) && damage > 2800 ) {
		if( attacker->query_temp("timer/high_dmg") + 900 < time() ) {
			log_file("SKILL_POWER_LOG", 
					sprintf("(%s)%s > 2800 damage: query_temp damage = %d, str = %d, enforce = %d. \n",
					ctime(time()),
					attacker->name(1)+"("+ attacker->query("id")+")", 
					attacker->query_temp("apply/damage"),
					attacker->query("str"),
					attacker->query("force_factor")
				));
			tell_object(attacker,HIR"系统记录：你的攻击/防守状态出现异常。请暂停游戏，向在线巫师汇报。\n"
"若无在线巫师，请退出游戏重新登陆。故意利用BUG牟利者将不受风云欢迎。\n"NOR);
			attacker->set_temp("timer/high_dmg", time());
		}
	}
	return damage;
}


int basic_armor(object victim)
{
	int armor, eff_ness, absorb_vic;
	string absorb_skill;

	if( victim->query_skill("iron-cloth") ) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if( absorb_skill ) {
			if( !(eff_ness = SKILL_D(absorb_skill)->ic_effect()) ) {
				eff_ness = 100;
			}
			absorb_vic = victim->query_skill("iron-cloth",1) /2
					+ victim->query_skill(absorb_skill) * eff_ness/200
					+ victim->query_temp("apply/iron-cloth");
		} else {
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1) /2
							+ victim->query_temp("apply/iron-cloth");
		}
	} else {
		absorb_vic = victim->query_temp("apply/iron-cloth");
	}
	return absorb_vic;
}

int help(object me)
{
   write(funcall(#'read_file,__DIR__"score"));
    return 1;
}
