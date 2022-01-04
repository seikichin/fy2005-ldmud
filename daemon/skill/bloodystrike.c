// bloodystrike.c

// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;

void setup() {
	set("name","密宗大手印");
	set("type","unarmed");
	set("effective_level",110);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","lama");
	set("parry_msg", 			({
			"$n双掌微合，使出一招「千里迎刹佛」，「啪」的一声将$N的$w夹在双掌之间。\n",
			"$n略一转身，一招「撒手离红尘」拍向$N拿着$w的手。\n",
			"$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n步走阴阳，一招「我佛慈悲怀」虚空拍出三掌，逼得$N撤招自保。\n",
			"$n施展出「万象皆归空」，轻描淡写的化解了$N的攻势。\n",
			})
	);

	action = ({
			([      "action":               
			"$N使出一招「苦海端无涯」，左掌虚幌，右掌穿出击向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                100,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出一招「地狱似有门」，左掌化虚为实击向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                 70,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出密宗大手印中的「天堂却无路」，一掌拍向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                50,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N双掌一错，使出「密宗为独尊」，对准$n的$l连续拍出",
			        "dodge":                100,
			        "parry":                100,
			        "force":                150,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N左掌立于胸前，右掌推出，一招「万念皆是空」击向$n$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                140,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出「佛云以杀止杀」，身形凌空飞起，从空中当头向$n的$l出掌攻击",
			        "dodge":                200,
			        "parry":                200,
			        "force":                150,
			        "damage_type":  "瘀伤"
			]),
	});
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
