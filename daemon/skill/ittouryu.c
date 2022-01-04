//mimicat@fy4
//ittouryu.c
inherit SKILL;

void setup(){
	set("name","一刀流剑术");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","ninja");
	set("parry_msg", ({
        	"$n一招「切返」以守为攻，化解了$N的攻势。\n",
		"$n突然从怀中掏出一把短刀，「二刀」当地一声挡住了$N的攻击。\n",
	}) );
		set("unarmed_parry_msg", ({
    		"$n一招「切返」以守为攻，化解了$N的攻势。\n",
		"$n突然从怀中掏出一把短刀，「二刀」当地一声挡住了$N的攻击。\n",
	}) );
	action = ({
		([      "action" : 
		"$N双手持刀，高举过顶，突然向$n攻出一招「南无三」，$w以破竹之势直奔$n的要害而去",
		        "dodge" : 10,
		        "parry" : 20,
		        "damage" : 120,
		        "damage_type" : "割伤",
		]),
		([      "action" : 
		"$N一招「地狱」猛地挥动$w向$n当头击下，$n退了一步，但$w的刀气不依不饶地袭向$n",
		        "dodge" : 17,
		        "parry" : 14,
		        "damage" : 120,
		        "damage_type" : "瘀伤",
		]),
		([      "action" : 
		"$N手中的$w刀光暴长，「岚」！不可一世地撞向$n",
		        "dodge" : 12,
		        "parry" : 11,
		        "damage" :110,
		        "damage_type" : "砍伤",
		]),
		([      "action" : 
		"$N挥动$w，一招「叶切合」如蛆附骨，点点不离$n",
		        "dodge" : 80,
		        "parry" : 80,
		        "damage" : 140,
		        "damage_type" : "刺伤",
		]),
		([      "action" : 
		"$N手中的$w在$n攻击的间隙中抢攻了进去，$N手中的$w有如梦一般罩了下去",
		        "dodge" : 70,
		        "parry" : 70,
		        "damage" : 90,
		        "damage_type" : "刺伤",
		]),
		([      "action" : 
		"$N低头躲过$n的一击，接着想也不想，反手一招「浮舟」$w带着三分惆怅，斩向$n的胸口",
		        "dodge" : 120,
		        "parry" : 120,
		        "damage" : 120,
		        "damage_type" : "割伤",
		]),
	});
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "浪人的悲哀" )!= 1) 
		return notify_fail("天枫十四郎未答应转授你这门武功。\n");
	if (({int})me->query("tianfeng/ittouryu")!=1){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	if( ({int})me->query("max_force") < 500 ) {
        return notify_fail("你的内力不够，没有办法练一刀流剑术。\n");
	}
	 return 1;
}*/

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
