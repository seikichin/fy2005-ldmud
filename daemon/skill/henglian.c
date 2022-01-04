// jin-gang.c
inherit SKILL;
void setup() {
	set("name","十三太保横练");
	set("type","iron-cloth");
	set("effective_level",100);
	
	set("usage/iron-cloth",1);
	set("ic_effect",50);
	set("bounce_ratio",10);
	set("difficulty",400);
	set("skill_class","fugui");
        set("absorb_msg", ({
	        "$n不闪不避，竟硬接了$N这一招。\n",
	        "$n神气贯通，内劲运行全身上下，对抗$N的这一招。\n",
	        "$n冷然一笑，两臂一震，已将$N的出招震开。\n",
        }) );
}


int valid_learn(object me){
	
	if( ({string})me->query("gender") != "男性" ) {
        	return notify_fail("十三太保横练是只有男子才能练的武功。\n");
	}
	
	if( ({int})me->query_skill("skyforce",1)+20 < ({int})me->query_skill("henglian",1)) {
        	return notify_fail("你的碧空心法修为不够，无法领悟更高深的十三太保横练。\n");
	}
	return ::valid_learn(me);
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
