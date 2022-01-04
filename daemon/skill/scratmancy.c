// scratmancy.c
inherit SKILL;

void setup() {
	set("name","三清符术");
	set("type","scratching");
	set("difficulty",250);
	set("effective_level",200);
	set("practice_limit",100);
	set("usage/scratching",1);
	set("skill_class","taoist");
}

int valid_learn(object me) {
	if(({int})me->query_skill("taoism",1) < ({int})me->query_skill("scratmancy",1)) {
		return notify_fail("你的天师正道修为不够，无法领悟更高深的三清符术。\n");
	}
	
	return 1;
}

int practice_skill(object me)
{	
	object bug;
	
	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"+ bug->name() + "吧！\n");

	if( ({int})me->query("mana") < 10 )
		return notify_fail("你的法力不够。\n");

	if( ({int})me->query("sen") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("你闭目凝神，神游物外，开始修习三清符术中的法术....\n");
	if( random(({int})me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = clone_object("/obj/npc/mind_bug");
		else		bug = clone_object("/obj/npc/mind_beast");

		write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->set("combat_exp", ({int})me->query("combat_exp")+100);
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n");
	}	
	else return 1;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
