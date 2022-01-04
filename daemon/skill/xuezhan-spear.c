// xuezhan-spear.c

inherit SKILL;
void setup(){
	set("name","血战枪法");
	set("type","spear");
	set("difficulty",250);
	set("usage/spear",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("effective_level",160);
	set("skill_class","fugui");
 	set("parry_msg", ({
		"$n枪法一变，使出「流星飞驶」$v直刺$N,逼得$N连退数步。\n",
		"$n枪势平平凡凡的一招「横架金梁」，竟令$N无法下手，攻势顿时慢了下来。\n",
		"$n手中的$v抖出一片枪花，一式「怒海惊涛」分刺$N的身法中的数处破绽。\n",
		"$n一声轻啸，身形换化「鹏搏九霄」，手中的$v反刺$N的前胸。\n",
	        "$n身随枪走，$v「乌龙搅柱」,格开了$N的$w。\n",
	        "$n双脚连踢，枪式成「迎风振翼」，手中的$v舞得密不透风，封住了$N的攻势。\n",        
	}) );

	set("unarmed_parry_msg", ({
		"$n枪法一变，使出「流星飞驶」$v直刺$N,逼得$N连退数步。\n",
		"$n枪势平平凡凡的一招「横架金梁」，竟令$N无法下手，攻势顿时慢了下来。\n",
		"$n手中的$v抖出一片枪花，一式「怒海惊涛」分刺$N的身法中的数处破绽。\n",
		"$n一声轻啸，身形换化「鹏搏九霄」，手中的$v反刺$N的前胸。\n",
        	"$n身随枪走，$v「乌龙搅柱」,格开了$N。\n",
        	"$n双脚连踢，枪式成「迎风振翼」，手中的$v舞得密不透风，封住了$N的攻势。\n",       
	}) );	
	action = ({
        ([      "action":               
"$N手中$w起起伏伏，忽上忽下，正是一招「血海苍茫」，枪锋泛起一片寒光，\n"
"攻向$n的$l",
                "damage":               40,
                "dodge":                40,
                "parry":                -40,
                "force": 		100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N身形一缓，聚气凝神，使出一招「天河血洗」，身形紧绷如弓，以$w为箭，\n"
"趁$n一个破绽，如电射向$n",
                "damage":               60,
                "dodge":                20,
                "parry":                30,
                "force": 		50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
	"$N卖个破绽，却于$n疏乎之际，使出一招「血踪万里」，倒过枪柄忽如其来\n"
"的敲向$n$l",
                "damage":               60,
                "dodge":                -30,
                "parry":                60,
                "force": 		75,                
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N真力灌注$w，简简单单的横划出去，一招平凡的「万岳朝宗」，在$N手中\n"
"竟有如斯威力",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "force": 		75,           
                "damage_type":  "刺伤"
        ]),
	([      "action":               
"$N手中$w一晃，转身就走，突然一记「万劫不复」由腋下刺出，$n发现时，\n"
"枪尖已灵蛇般刺到$n眼前",
                "damage":               60,
                "dodge":                30,
                "parry":                60,
                "force": 		50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w高举，凝神静气，一式「六道轮回」自上直击而下，$n犹如身处\n"
"炼狱洪炉，不知所措",
                "damage":               60,
                "dodge":                30,
                "parry":                60,
                "force": 		150,
                "damage_type":  "刺伤"
        ]),
	});
}

int damage_level(object me)
{
	int skill, n, ratio;
	if (me) {
		skill=me->query_skill("xuezhan-spear",1);
		ratio = me->query("kee")*1000 / me->query("max_kee");		
		n = 700 - ratio;
		if( ANNIE_D->check_buff(me,"fg-youdishenru") ) {
			n = 250;
		}
		if (n < 0 ) n = 0;
		return n;
	}
	return 0;
}
		
int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill = me ->query_skill("xuezhan-spear",1);
		if (skill < 200)
			return 250;
		else
			return 400;
	}
	return 250;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
