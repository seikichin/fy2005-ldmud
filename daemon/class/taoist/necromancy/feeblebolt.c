// feeblebolt.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, lvl, cost;
	int dam, flag, leach ;

	if( me->query("class") != "taoist" ) {
		return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
	}
	lvl = me->query_skill("necromancy",1);
	if( lvl < 60 ) {
		return notify_fail("『苍灵之箭』需要60级的三清道术！\n");
	}
	if( me->query_skill_mapped("force") != "gouyee" ) {
		return notify_fail("三清道术需使用谷衣心法的运转法门。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("这种法术只能对战斗中的对手使用。\n");
	}
	if( ANNIE_D->check_buff(me, "manatwist") > 0 ) {
		flag = 3;
	} else {
		flag = 1;
	}
	cost = (20+lvl/2)*flag;
	if( me->query("mana") < cost || me->query("sen") < cost ) {
		return notify_fail("『苍灵之箭』至少需要"+cost+"点心神和法力。\n");
	}
	if( userp(me) ) {
		me->add("mana", -cost);
	}
	msg = BBLU + HIY "$N口中喃喃地念著咒文，左手一挥，手中聚起一团黄光射向$n！\n" NOR;
	me->set_temp("last_sqpfm_used", 1);
	me->add_temp("apply/spells", lvl*2);
	if( COMBAT_D->do_magic_attack(me, target, "spells", "sen", 0) ) {
		msg += BBLU + HIR "结果「嗤」地一声，黄光从$p"+HIR"身上透体而过，拖出一条长长的七彩光气，\n"
					"光气绕了回转过来又从$N"+HIR"顶门注入$P"+HIR"的体内！\n" NOR;				
		message_vision(msg, me, target);
		ap = me->query_skill("spells");
		damage = 60 + ap*ap/540 + random(ap*ap/540);
		if( flag == 3 ) {
			damage *= 2;
		}
		// +20% chance double damage.
		if( !me->query("possessed") &&random(100) < F_ABILITY->check_ability(me,"feeble_add",1)*2 ) {
			damage = damage*2;
		}
		if( me->query("possessed") ) {
			damage = damage*8/10; // Pet damage*80/100
		}
		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
		damage = damage*(100+F_ABILITY->check_ability(me,"3_bolt1_add",3)*2)/100;
		target->receive_damage("sen", damage, me);
		target->set_temp("damaged_during_attack", damage);
		// each aa level +5% damage 
		leach = damage/2;
		me->receive_fulling("sen", leach, me);
		target->add_hate( me, -leach);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,damage);
		
	} else {
		msg += YEL"但是被$n机灵地躲开了。\n"NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/spells", -lvl*2);
	me->perform_busy(2);
	return 1;
}




/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
