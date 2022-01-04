// modified by mimicat@fy4
// qidaoforce.c

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","棋道");
	set("type","force");
	set("usage/force",1);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","legend");
	set("effective_level",150);
	set("damage_level",200);
	set("no_refund",({"diesword","shortsong-blade"}));
	set("difficulty",400);
	set("parry_msg",  ({
		"$n右臂回转，内力排山倒海地将$N的招式震开。\n",
		"$n一声大喝，周身真气震荡，挡住了$N的攻势。\n",
		"$n脚步不丁不八，右手高左手低，$N的攻势如泥牛入江消失无踪。\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n右臂回转，内力排山倒海地将$N的招式震开。\n",
		"$n一声大喝，周身真气震荡，挡住了$N的攻势。\n",
		"$n脚步不丁不八，右手高左手低，$N的攻势如泥牛入江消失无踪。\n",
	}) );
	action = ({
        ([      "action":"$N使出一招「镇神头」，左手聚出一团真气，从上而下，击向$n的$l",
                "parry":		400,
                "dodge":		500,
                "damage":		200,
                "damage_type":  "内伤"
        ]),
        ([      "action":"$N使出一招「大斜」，右手聚出一团真气，斜斜击向$n的$l",
                "parry":		100,
                "dodge":		600,
                "damage":		250,
                "damage_type":  "内伤"
        ]),
	([ 	"action":"$N使出一招「双飞燕」，双手聚出一团真气，左右同时击向$n的$l",
                "parry":		200,
                "dodge":		300,
                "damage":		300,
                "damage_type":  "内伤"
        ]),
	([	"action":"$N使出一招「倒垂莲」，全身腾空而起，运起全身的真气击向$n的$l",
                "parry":		400,
                "dodge":		400,
                "damage":		400,
                "damage_type":  "内伤"
        ]),
	});
}

int valid_enable(string usage) 
{ 
	return usage=="unarmed"||usage=="force"|| usage=="parry"; 
}

mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra/*, dream*/;
	string skill/*,message=""*/;
	object weapon;
		
	extra = me->query_temp("pfm/qidaoforce_juqi");
	if ( extra <= 0 ) 	return;
	
	if (me->query_temp("pfm/legend_berserk"))	extra = extra*2;
			
	skill = objectp(weapon = me->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
    if (skill == "unarmed")	extra = extra/2;
    
    skill = me->query_skill_mapped(skill);
    if (!skill || SKILL_D(skill)->skill_class()!="legend") {
		return;
    }
	
//	extra = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	victim->receive_damage("kee",extra,me);
	
	if (me->query("family/master_id")=="master xuerui")
			message_vision(WHT"\n$N身侧的玉色光芒忽如蝶翼般片片飞向$n，$n"+WHT"只觉经脉中一阵灼痛。\n"NOR,me, victim);
		else 
			message_vision(HIC"\n$N将内力凝为一线，攻入$n"+HIC"的体内。\n"NOR, me, victim);
	return;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}