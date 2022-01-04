// Mimicat@fy4
// kwan-yin-spells.c
inherit SKILL;
void setup() {
	set("name","观音六字明咒");
	set("type","spells");
	set("usage/spells",1);
	set("effective_level",200);
	set("skill_class","lama");
	set("difficulty",250);
}

int valid_learn(object me)
{
	if( me->query_skill("lamaism", 1)+20 < me->query_skill("kwan-yin-spells", 1) ) {
		return notify_fail("你的密宗佛法修为不够，无法领悟更高深的观音六字明咒。\n");
	}
	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
