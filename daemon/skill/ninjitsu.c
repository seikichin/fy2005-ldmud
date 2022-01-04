// ninjitsu.c

inherit SKILL;

void setup(){
	set("name","忍术");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("skill_class","ninja");
	set("effective_level",180);
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "浪人的悲哀" )!= 1) 
		return notify_fail("天枫十四郎未答应转授你这门武功。\n");
	if (({int})me->query("tianfeng/ninjitsu")!=1){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	return 1;
}*/


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
