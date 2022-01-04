// xiaochengforce.c

inherit SKILL;

void setup(){
	set("name","小乘心经");
	set("type","force");
	set("usage/force",1);
	set("effective_level",140);
	set("difficulty",150);
	set("skill_class","shaolin");
}


int valid_learn(object me){
	if(({int})me->query("bellicosity") > ({int})me->query_skill("xiaochengforce",1)* 50 ) {
        	return notify_fail("你的杀气太高，无法领悟更高深的小乘心经。\n");
	}
	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
