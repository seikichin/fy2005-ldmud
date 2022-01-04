// TIE@FY3
inherit SKILL;
void setup()
{
	set("name","悟彻波风斧法");
	set("skill_class","shaolin");
	set("type","axe");
	set("effective_level",200);
	set("usage/axe",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("difficulty",200);
		
	set("parry_msg", ({
			"结果$n一招「禅心落寞」，挥动手中$v格开了$N的$w。\n",
			"结果$n手中$v一分，一招「入魔入佛」，斜劈$N的$w。\n",
			"结果$n手中$v抡动如飞，一招「洪波万里」，荡开$N的$w。\n",
			"结果$n手中$v飞速旋转，一招「不解成舟」，反扫$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n手中的$v舞动如飞，一招「不动不摇」，封住了$N的攻势。\n",
			"$n身影晃动，一招「千潭月朗」，反砍$N的下盘。\n",
			"$n身形一矮，一招「满地蒿蓬」，躲过$N的攻势。\n",
			"$n手中的$v自上而下，一招「始堪耕地」，反劈$N的要害。\n",
	}) );	
	action = ({
		([      "action":               
				"$N手中$w抡开，挟着呼呼风声，一招「树喧每每」，直取$n的各处要害！",
				"dodge":                -150,
				"parry":                -200,
				"post_action":  "bash_weapon",
				"damage_type":  "割伤"
		]),
		([      "action":               
				"$N纵身一跃，手中$w斧风呼啸，一招「月现长空」，横空向$n$l劈去！",
				"dodge":                -160,
				"parry":                -210,
				"post_action":  "bash_weapon",
				"damage_type":  "割伤"
		]),
		([      "action":               
				"$N手中$w接连劈出，，一招「渊源不尽」，旋风般砍向$n$l！",
				"dodge":                -150,
				"parry":                -150,
				"post_action":  "bash_weapon",
				"damage_type":  "割伤"
		]),
		([      "action":               
				"$N使出一招「万派朝宗」，手中$w舞动，身随斧势，化作一溜烟尘，滚滚奔向$n的$l！",
				"dodge":                -140,
				"parry":                -240,
				"post_action":  "bash_weapon",
				"damage_type":  "割伤"
		]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	int ratio;
	ratio = F_ABILITY->check_ability(me, "3_weapon_add", 3) * 2;
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "blade" || ob->query("skill_type") == "staff" ) {
			ratio += 15;
		}
	}
	return damage_bonus*ratio/100;

}

int effective_level(object me)
{
	int skill,n;
	if( me ) {
		skill = me->query_skill("wuche-axe",1);
		if( skill <= 150 || (me->query("class") != "shaolin" && userp(me)) ) {
			return 150;
		}
		if( skill >= 170 ) {
			return 200;
		}
		n=(skill-150)/4*10+150;
		return n;
	}
	return 200;
}

int skill_difficulty()
{
	object me = this_player();
	int skill, n;
	if( me && userp(me) ) {
		skill = me ->query_skill("wuche-axe",1);
		if( skill < 150 ) {
			return 200;
		} else {
			return 400;
		}
	}
	return 200;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}