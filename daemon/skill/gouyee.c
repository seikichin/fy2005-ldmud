// gouyee.c

inherit SKILL;
void setup() {
	set("name","谷衣心法");
	set("effective_level",120);
	set("type","force");
	set("usage/force",1);
	set("skill_class","taoist");
	set("difficulty",200);
}

int valid_learn(object me)
{
    	if(({int})me->query_skill("taoism",1) < ({int})me->query_skill("gouyee",1)){
        		return notify_fail("你的天师正道不够，无法提升谷衣心法的造诣。\n");
		}
    	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
