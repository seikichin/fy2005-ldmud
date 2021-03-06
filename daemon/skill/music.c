///music.c 五音十二律
// 乐律十二律，是为黄钟、大吕、太簇、夹钟、姑洗、中吕、蕤宾、林钟、夷则、南吕、无射、应钟。
// 此是自古已有，据说当年黄帝命伶伦为律，闻凤凰之鸣而制十二律。
// 瑶琴七弦，具宫、商、角、微、羽五音，一弦为黄钟，三弦为宫调。五调为慢角、清商、宫调、慢宫、及蕤宾调。

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","琴道");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("effective_level",150);
	set("skill_class","baiyun");

	set("parry_msg", ({
	        "$n左手拇指食指虚捻，右手轻挥，空气中骤生『变商』之音，一轮音波将$N迫开。\n",
	        "$n两手凌空虚划，冷冽的气劲吹过，忽传『清徵』之音，$N不觉有点心神撼动。\n",
	        "$n凝神专著，伸手轻抚，如拨琴弦，耳侧传来『正宫』之调，$N一时茫然不知所以。\n", 
	}) );
	set("unarmed_parry_msg", ({
	        "$n左手拇指食指虚捻，右手轻挥，空气中骤生『变商』之音，一轮音波将$N迫开。\n",
	        "$n两手凌空虚划，冷冽的气劲吹过，忽传『清角』之音，$N不觉有点心神撼动。\n",
	        "$n凝神专著，伸手轻抚，如拨琴弦，耳侧传来『正宫』之调，$N一时茫然不知所以。\n", 
	}) );
	action = ({
        ([      "action":               "$N轮指急抚，阵阵疾风如珠玉落盘，激起『变羽』之音，袭向$n的$l",
                "dodge":                180,
                "parry":                20,
		"damage":		70,
                "damage_type":  	"刺伤",
        ]),
        ([      "action":               "$N信手轻敲，『变角』声沉，周围忽起鼓点隆隆，如十面埋伏围向$n",
                "dodge":                140,
                "parry":                90,
		"damage":		20,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左手凝气，右手横拉而过，『清商』之调如无边丝雨，漫漫飘向$n的$l",
                "dodge":                120,
                "parry":                120,
		"damage":		90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N伸掌直拍，疾风忽起，流云四散，在气流波动的『正商』之音中，击向$n的$l",
                "dodge":                160,
                "parry":                20,
                "damage":               10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发『变徵』之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
	});

}


int valid_enable(string usage) 
{ 
	object me;
/*	me=this_player();
	if(!me){
		return usage=="unarmed"||usage=="magic"; 
	}
	if(!userp(me)){
		return usage=="unarmed"||usage=="magic"; 
	}
	else*/
		return usage=="unarmed"||usage=="magic";
}



mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, dream;
	string message="";
	
	if (me->query("class")!="baiyun")	return;
	extra = me->query_skill("music",1);
	message_vision(WHT"\n$N双手连弹，『宫、商、角、微、羽』五音齐发，声如裂帛，$n浑身剧颤。\n"NOR,me, victim);	
	victim->perform_busy(1);
	return;
}


int help(object me)
{
        write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
