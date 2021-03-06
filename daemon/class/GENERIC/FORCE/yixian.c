// Silencer @ FY4 workgroup. Aug.2005

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int stage, force, lvl, duration, amount1;
	object obj, *mem;
	string msg, name;
	mapping buff;

	lvl = me->query("cont_quest");
	if( lvl < 5) 	
		return notify_fail("使用『海天一线』至少需要连续完成5个天机老人的任务，\n"
"你现在只连续完成了"+chinese_number(lvl)+"个。\n");
		
    if (me->is_fighting())
       	return notify_fail("战斗中无法使用『海天一线』\n");
    		
	if(!target ) target=me;
	if(target!= me) {
		return notify_fail("『海天一线』只能用于自身。\n");
	}
	
	if (ANNIE_D->check_buff(target, "quest_parry"))
		return notify_fail("此人已经在使用类似的心法了。\n");	
	
	if (me->query("force")< 300)
        	return notify_fail("『海天一线』至少需要300点真气。\n");
    if (userp(me))	me->add("force",-300);
    
    // STage ADVANCE PERFORM, 
    
    name = "风云·海天一线";
    
    if (lvl >= 15)		{lvl = 15; name += "ＩＩＩ";} 
    else if (lvl >=10)	{lvl = 10;name += "ＩＩ";}
    else				{lvl = 5;name += "Ｉ";}
    
    amount1 = lvl;       	
	
	me -> delete("cont_quest");
	
	duration = 1200;
	
	msg = HBRED + HIY"$N右手一翻，左手骈指如刃，由右腋下慢慢递出，虚空划出一道弧线。\n"NOR;
		
	buff =
		([
			"caster": me,
			"who":  target,
			"type": "quest_parry",			// in parry_attack of combatd
			"att":	"bless",
			"name":	name,
			"buff1":"apply/quest_parry",
			"buff1_c":amount1,
			"time":  1200 ,
			"buff_msg": msg,
			"special_func":0,
		]);
		
    ANNIE_D->buffup(buff);
	me->perform_busy(1);
	return 1;
}



