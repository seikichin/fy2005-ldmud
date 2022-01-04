// nine-moon-sword.c
#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","九阴赤炼剑法");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","shenshui");
	set("effective_level",100);
	set("difficulty",200);
	set("practice_limit",100);
	set("parry_msg", ({
		"$n使出九阴赤炼剑中「阴风狂吼」，将$N手中的$w引偏了出去。\n",
		"$n踏坎位，入生门，手中的$v往上一撩，架住了$N手中的$w。\n",
		"$n向$N左侧进一步，手中的$v顺着$N的$w滑下，急削$N握$w的手指。\n",
		"$n手中的$v一抖，一招「九朵赤炼」，$v幻出九条剑影，锁住了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n气透剑尖，一招「阴风刺骨」，强劲的剑气直取$N的咽喉。\n",
		"$n反手一剑，$v象一条孽龙，直扑$N的手腕。\n",
		"$n右脚后踏一步，$v递左手，右手向$N虚按，一股劲力使$N抬不起手。\n",
		"$n转身，$v突然从腋下刺出，一招「沙地赤蝎」，刺向$N的手腕。$N慌忙撤招自保。\n",
	}) ); 	
	action = ({
		([	"name":			"阴魂不散",
			"action":		"$N使一招「阴魂不散」，手中$w剑光暴长，向$n的$l刺去",
			"dodge":		50,
 	  	         "parry":                240,
			"force":		170,
			"damage_type":	"刺伤"
		]),
		([	"name":			"阴气森森",
			"action":		"$N剑随身转，一招「阴气森森」罩向$n的$l",
			"dodge":		70,
			 "parry":                180,
			"force":		200,
			"damage_type":	"刺伤"
		]),
		([	"name":			"阴云迭起",
			"action":		"$N舞动$w，一招「阴云迭起」挟著无数剑光刺向$n的$l",
			"dodge":		40,
			 "parry":                150,
			"damage":		90,
			"damage_type":	"刺伤"
		]),
		([	"name":			"阴曹地府",
			"action":		"$N手中$w龙吟一声，祭出「阴曹地府」往$n的$l刺出数剑",
			"dodge":		40,
			 "parry":                160,
			"damage":		40,
			"damage_type":	"刺伤"
		]),
		([	"name":			"阴阳两仪",
			"action":		"$N手中$w剑光暴长，一招「阴阳两仪」往$n$l刺去",
			"dodge":		60,
			 "parry":                150,
			"damage":		120,
			"damage_type":	"刺伤"
		]),
		([	"name":			"阴日阳月",
			"action":		"$N手中$w化成一道光弧，直指$n$l，一招「阴日阳月」发出虎哮龙吟刺去",
			"dodge":		60,
			 "parry":                140,
			"damage":		150,
			"damage_type":	"刺伤"
		]),
	});
}

int valid_learn(object me)
{

	if( ({string})me->query_skill_mapped("force") != "nine-moon-force" ) {
        	return notify_fail("九阴赤炼剑法必须配合九阴心经才能练。\n");
	}
/*	if (me->query_skill("nine-moon-sword",1) >= me->query_skill("nine-moon-force",1)){
			return notify_fail("你的九阴心经火候不够。\n");
	}		*/
	return ::valid_learn(me);
}


mixed parry_ob(object victim,object me)
{
	int mylvl, extra, damage;
	string msg;
	
	if( extra = me->query_temp("nine-moon-force_poison") ) {
		extra = extra/2;
		damage = COMBAT_D->magic_modifier( me, victim, "kee", extra);
		victim->receive_damage("kee", damage, me);
		victim->receive_wound("kee", damage, me);
		if( !victim->query_temp("weapon") ) {	
			return MAG"$N只觉触手处紫气一闪，缕缕阴寒锥心而至！\n"NOR;
		} else {
			return MAG"$N只觉一层淡淡的紫气从兵刃上蔓延而来，刺骨的寒气几乎令手腕转动不灵。\n"NOR;
		}
	}
return "";
}

int effective_level(object me)
{
	int skill,n;	
	if( me ) {
		skill = me->query_skill("qingpingsword", 1);
		if( skill < 109 ) {
			return 100;
		} if( skill > 200 )	{
			return 175;
		}
		if( skill <= 150 )	{
			return (skill/10*10);
		}
		return (150 + (skill-150)/10*5);
	}
	return 150;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
