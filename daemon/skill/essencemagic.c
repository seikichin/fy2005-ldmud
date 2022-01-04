// essencemagic.c

inherit SKILL;

void setup() {
	set("name","八识神通");
	set("type","magic");
	set("effective_level",150);
	set("difficulty",300);
	set("usage/magic",1);
	set("skill_class","bonze");
}

int valid_learn(object me)
{
	if( ({int})me->query_skill("buddhism",1) < 10
	||	({int})me->query_skill("buddhism",1) <= ({int})me->query_skill("essencemagic",1) )
		return notify_fail("你的佛法修为还不够高深，无法学习八识神通。\n");
	return 1;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
