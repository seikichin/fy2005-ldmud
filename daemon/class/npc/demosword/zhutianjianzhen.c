// 2009 FengYun
// Edit by hippo 2009.11


#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int busy_target(object me,object target);

int perform(object me, object target)
{
	string msg;
	int extra,xd;
	int i, flag,flag2,flag3;
	object weapon,*pros,ob;
			string *color=     ({
	HIR,HIC,HIW,HIY,
	});

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『诛天剑阵』只能对战斗中的对手使用。\n");
		
/*	
	if (me->query("class") && userp(me))
		return notify_fail("『诛天剑阵』只有普通百姓才能使用。\n");
*/
	
	if (me->query_skill("demosword",1) < 150)
		return notify_fail("你的九邪剑法等级不足以施展『诛天剑阵』。\n");
	
	if (me->query_skill("xiaodao",1) < 150)
		return notify_fail("你的孝道等级不足以施展『诛天剑阵』。\n");

	xd = me->query_skill("xiaodao",1);
		
	extra = me->query_skill("demosword",1) / 50;
	if (extra < 1)
		extra = 1;
	if (extra > 4)
		extra = 4;
/*
	if (wizardp(me))
	{
		if (me->query("marry"))
		{
			//seteuid(getuid());
			//ob = clone_object(LOGIN_OB);
			//ob->set("id", "hippo");
			//name_c = me->query("marry");
			ob = FINGER_D->acquire_login_ob(me->query("marry"));
			owner = LOGIN_D->make_body(ob);		
			tell_object(me,CYN"（"+owner->query("marry")+"）\n"NOR);
			
			if (owner->query("marry"))
				extra = 1 + random(extra);	// 嫁人了
			else {
				flag3 = 1;					// 嫁了另一个普通百姓 >"< 不能相信... *bud *admire
			}
			destruct(ob);
		}
	}
*/
	weapon=me->query_temp("weapon");
	
	msg = CYN  "\n$N口中念念有词，长剑挥舞，状若癫狂，八方地气齐集而来，在\n$n脚下汇集成一个偌大符文，破土裂地而出！\n\n" NOR;
	message_vision(msg,me,target);

	i = extra-1;
	flag = 0;
	flag2=0;

	msg = color[i]+"　　　　　　　　ф　　ξ　　ψ\n\n　　　　　　δ　　　　　　　　　з\n\n　　　　　　τ　　　　"+MAG"Ж"+color[i]+"　　　　ζ\n\n　　　　　　д　　　　　　　　　ε\n\n　　　　　　　ω　　　δ　　　υ\n"NOR;
	message_vision(msg,me,target);

	target->set_temp("no_check_pfm_win",1);
	target->add_temp("combat_no_report",1);
	target->add_temp("buff/no_abs",1);

	for (i=0; i<extra; i++)
	{
		me->add_temp("apply/attack", xd*(i+1)/4);
		me->add_temp("apply/damage", xd*(i+1)/8);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM);
		target->set_temp("skip_damage_record",1);
		if (target->query_temp("damaged_during_attack"))
			flag = 1;
		if (me->query_busy() && flag3 == 1)	// cancel parry/dodge/ob_hit busy! ultimate perform... 
			me->stop_busy();
		if (target->query_temp("damaged_during_attack") && i == 3)	// 4th hit
			flag2 = 1;
		me->add_temp("apply/attack", -xd*(i+1)/4);
		me->add_temp("apply/damage", -xd*(i+1)/8);
	}
	
	if (target) {
		target->add_temp("combat_no_report",-1);
		target->add_temp("buff/no_abs",-1);
	
		if (!flag)
			message_vision(HIG"\n$n"HIG"气定神凝，丝毫不乱，闪身避开这式『诛天剑阵』。\n"NOR,me,target);
		else
		{
			message_vision(HIB"\n符文闪电般穿过$n"HIB"身体，带着数条血箭直冲云霄。\n"NOR,me,target);
			if (flag2)
			{
				target->force_busy(target->query_busy()+1);
				message_vision(HIB"$n"HIB"为符文去势带动，凌空飞起十尺，在空中打了个转，重重摔回地面。\n"NOR,me,target);
			}
			COMBAT_D->report_status(target);
			COMBAT_D->win_lose_check(me,target,1);
		}
		target ->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

	if (me->query("class") && userp(me)) {
		if (extra <= 2)
			me->perform_busy(4);
		else
			me->perform_busy(5);
	} else {
		if (extra <= 2)
			me->perform_busy(2);
		else
			me->perform_busy(3);
		}


	return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

