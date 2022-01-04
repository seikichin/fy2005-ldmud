inherit SKILL;

void setup() {
	set("name","云梦五花锦");
	set("type","herb");
	set("effective_level",200);
	set("usage/herb",1);
	set("difficulty",200);
	set("skill_class","knight");
}


int valid_learn(object me)
{
	if( me->query_skill("herb", 1) < me->query_skill("dream-herb",1)) {
		return notify_fail("你的药道心法火候不足，无法练云梦五花锦。\n");
	}
	return 1;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
