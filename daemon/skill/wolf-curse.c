inherit SKILL;

void setup() {
	set("name","天狼血咒");
	set("type","cursism");
	set("effective_level",150);
	set("usage/cursism",1);
	set("difficulty",200);
	set("skill_class","wolfmount");
}

int valid_learn(object me)
{
	if( me->query_skill("summonwolf",1) < 200)
		return notify_fail("需要200级唤狼术才能领悟天狼血咒。\n");
	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
