inherit SKILL;
void setup() {
	set("name","乾坤无形");
	set("type","magic");
	set("usage/magic",1);
	set("skill_class","yinshi");
	set("effective_level",100);
	set("difficulty",300);
}

int valid_learn(object me)
{
    	object ob;
    	
    	if( me->query_skill("qiankunwuxing",1) >= me->query_skill("celecurse", 1))
    	   	return notify_fail("学习乾坤无形需要相同等级的通天降作基础。\n");
		
		return ::valid_learn(me);
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
