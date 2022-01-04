// yue-spear.c

inherit SKILL;

void setup() {
	set("name","岳家中平枪法");
	set("type","spear");
	set("effective_level",200);
	set("usage/spear",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","official");
	
	set("parry_msg",	({
		"$n豪气干云，吟道：「笑谈渴饮匈奴血」，手中的$v由下而上，荡开了$N的$w。\n",
		"$n吟道：「凭栏处，潇潇雨歇」，手中的$v舞得密不透风，将$N的$w封于丈外。\n",
		"$n慷慨的诵道：「莫等闲白了少年头，空悲切」，手中的$v化做漫天残照，荡开了$N的$w。\n",
		"$n手中的$v一抖，枪身暴长，向$N拿$w的手腕刺去。\n",
		})
	);
	set("unarmed_parry_msg",	({
		"$n使出一招「怒发冲冠」，将手中的$v舞得密不透风，封住了$N的攻势。\n",
		"$n使出一招「壮怀激烈」，整个人消失在一团枪影之中。\n",
		"$n抽身急转，$v直刺$N的双手。\n",
		"$n将手中的$v一抖，舞出无数枪影，迫得$N连连后退。\n",
		})
	);
	
	action = ({
			([      "action":               
					"$N口中吟道: 「待从头收拾旧山河，朝天阙。」，手中$w倒转，枪杆\n由下至上，直向$n的$l打去",
			        "dodge":                32,
			        "parry":                20,
			        "force" :               40,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N长叹道：「靖康耻，犹未雪，臣子恨，何时灭！」，手中$w晃出无数\n枪影，忽然一枪向$n的$l刺去",
			        "dodge":                10,
			        "parry":                40,
			        "force":                15,
			        "damage_type":  "刺伤"
			]),
			([      "action":               
					"$N面带忧色，吟道：「三十功名尘与土。」枪身突转，向$n的下盘扫去",
			        "dodge":                20,
			        "parry":                30,
			        "force":                50,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N一声清啸，「驾长车，踏破贺兰山缺。」，大踏步向前走来，手中$w\n平平递出，直取$n的$l",
			        "force":                30,
			        "dodge":                20,
			        "parry":                30,
			        "damage_type":  "刺伤"
			]),
			([      "action":               
					"$N低头吟哦：「八千里路云和月」，手中$w凌空虚点，蓦地进步跟身，\n向$n扫出一排枪影",
			        "dodge":                20,
			        "parry":                20,
			        "force":                30,
			        "damage_type":  "刺伤"
			]),
			([      "action":               
					"$N慷慨激昂的诵道：「壮志饥餐胡虏肉」，手中长枪忽左忽右，游移不定，募然反\n身向$n的$l挑去",
			        "dodge":                56,
			        "parry":                13,
			        "force":                10,
			        "damage_type":  "刺伤"
			]),
	});
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
