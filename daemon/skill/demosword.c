// Can't Parry.
// 普通百姓专用 *cat
// 吃pots
// coeff = 180，200级 360 enable 超过ittouryu 150*2=300 enable。
// book 九思剑谱，study 0 - 50, learn 100 - 150, research 150 - 200.
// perform 诛天剑阵 惟普通百姓可用，效果与xiaodao挂钩。
// 　　　　　　　　　破iron-cloth，不被PB/DB/OHB,1-4hit busy 2-3。

inherit SKILL;
void setup() {
	set("name","九邪剑法");
	set("effective_level",180);
	set("type","sword");
	set("difficulty",300);
	set("usage/sword",1);
	set("skill_class","npc");
	action = ({
        ([      "action":               
"$N手中$w斜斜一划，一式「一剑苍茫」带起一片光华刺向$n",
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N悄然低眉，手中$w一转，施出「双目无光」抖出两点剑花刺向$n",
                "dodge":                -140,
                "damage":               140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一振手中$w，三点飞华袭向$n，正是九邪剑中的「三生缘定」",
                "parry":                -210,
                "damage":               210,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一按，圈出一缕寒光铺天盖地而来，这一式乃是九邪剑着「四海为家」",
                "dodge":                280,
                "parry":                -280,
                "damage":               280,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一式「五谷不食」，反手一剑，顺手一剑，似已乱了分寸，却自有神奥其中",
                "dodge":                -350,
                "parry":                350,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一卷$w，倒持剑刃，满面悲戚，一式「六年魂断」笔直撞向$n",
                "dodge":                -420,
                "parry":                -420,
                "damage":               420,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N长叹一声，使出杀着「七窍风霜」，手中$w一点，已经隐去了剑光，只见一把凡\n铁般黯淡无华的$w平平刺向$n",
                "dodge":                490,
                "parry":                490,
                "damage":               490,
                "damage_type":  "刺伤"
        ]),
});

}

int effective_level(object me)
{
	
	if (me && userp(me))
	{
		if (!me->query("class"))
			return 180;
	}
	return 80;
}

int skill_difficulty() {
	
	object me = this_player();
	if (me && userp(me)) {
	if (!me->query("class"))
		return 300;
	}
	return 700;	
}

/*
int valid_learn(object me)
{
	if( me->query("class") ){
		return notify_fail("你门户之见已深，无法学习九邪剑法。\n");
	}
 	return ::valid_learn(me);
}
*/

mapping query_action(object me, object weapon)
{
	int i,level;
	level   = me->query_skill("demosword",1);
	if(level < 29) level = 29;
	for(i = sizeof(action); i > 0; i--)
		if(level >= i * 29)
			return action[random(i)];	// to get the 7th'hit,research 200->203.
	
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}


/*Edit By Hippo 2009.11*/
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

