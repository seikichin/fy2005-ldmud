// flying-dragon.c

inherit SKILL;
void setup() {
	set("name","飞龙探云手");
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",140);
	set("practice_limit",100);
	set("difficulty",150);
	set("skill_class","yinshi");
	set("parry_msg", ({
        	"$n双手急抓$N的手腕，$N手中的$w几乎脱手而出。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n并起二指，凌空虚点，指风直奔$N的周身大穴。\n",
	}) );
	
	action = ({
        ([      "action":               
"$N双手一挥，一招「翔龙在天」右手划向$n$l",
                "dodge":                30,
                "parry":                30,
                "damage":                80,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               
"$N身影缥渺，使一招「云龙突现」，转身左手往$n的$l拍去",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               
"$N身形忽然平地拔起，双手散出满天掌影，一招「神龙摆尾」往$n的$l挥去",
                "dodge":                30,
                "parry":                30,
                "damage":                140,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               
"只见$N双手一摆，顺著来势一招「画龙点睛」往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
	});
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
