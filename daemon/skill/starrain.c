// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void setup() {
	set("name","寒星雨觞");
	set("type","throwing");
	set("usage/throwing",1);
	set("usage/parry",1);
	set("skill_class","moon");

	set("effective_level",150);
	set("eff_parry_level",210);

	set("difficulty",250);
	set("practice_limit",50);

	set("parry_msg", ({
        "$n抽身急退，双手轻扬，$N阻住脚步，却是一式虚招。\n",
		"$n长袖乍展，只银华飞泻，潇潇如雨，将自身护于其中。\n",
		"$n飞舞轻旋，进退如据，令$N隔寸束手，变式落空。\n", 
	}) );
	set("unarmed_parry_msg", ({
        "$n抽身急退，双手轻扬，$N阻住脚步，却是一式虚招。\n",
		"$n长袖乍展，只银华飞泻，潇潇如雨，将自身护于其中。\n",
		"$n飞舞轻旋，进退如据，令$N隔寸束手，变式落空。\n", 
	}) );	

	action = ({
        ([      "action":               
"$N一拂长袖，只见星星点点$w纷飞而出，直似萤虫飞舞，有如天穹倾覆",
                "parry":                1,
				"damage":				4,
				"post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N大袖翻转，霎时间绛雪纷纷，$w飘如柳絮，弱似梨花，密密舞向众人身边",
                "parry":                2,
				"damage":				3,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N旋舞时幻起花雨满天，袖落处化作断霞千缕，无数$w漫天而出，不离不散的欺向敌人",
                "parry":                3,
				"damage":				2,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"只听$N一声清啸，双袖虚拍，袖中$w洒若冰魂急雨，微光粼动，竟似抵死缠绵",
                "parry":                4,
				"damage":				1,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
	});
}

int damage_level(object me)
{
	return me->query_skill("starrain",1)+50;
}

int accuracy_level(object me)
{
	return me->query_skill("starrain",1)+50;
}

int valid_learn(object me)
{
	if(!::valid_learn(me))
		return 0;
	if( me->query_skill("starrain",1)> 100 && me->query_skill("throwing", 1) < me->query_skill("starrain",1) ) {
		return notify_fail("你对基本的暗器收发之术尚未掌其精髓，怎能学这大巧大工的寒星雨觞？\n");
	}
	if( me->query("class") != "moon" && me->query_skill("starrain",1) >= 100 ) {
		return notify_fail("你已无法更深入的领悟寒星雨觞。\n");	// 必须RESEARCH。
	}
	return 1;
}

int valid_research(object me)
{
	if( me->query_skill("throwing", 1) < me->query_skill("starrain",1) ) {
		return notify_fail("你对基本的暗器收发之术尚未掌其精髓，怎能学这大巧大工的寒星雨觞？\n");
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob,*enemy;
	int i;
	if (me->query("class") != "moon" && userp(me))
		return 0;
	if (me->query_temp("annie/perform_starrain") && userp(me))
		return 0;
	if (me->query("annie/no-multi-target"))
		return 0;
	enemy = me->query_enemy();
	if (sizeof(enemy) < 2)
		return 0;
	me->set_temp("annie/multi-target",victim);

    return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("starrain", 1);
		if( skill < 200 ) {
			return 250;
		} else {
			return 400;
		}
	}
	return 250;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
