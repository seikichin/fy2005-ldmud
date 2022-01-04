// heart-listening.c
// annie 07.2003
// 用以增加sen，附带一个小小用处cast telepathy

inherit SKILL;
void setup(){
	set("name","幻念聆音");
	set("difficulty",200);
	set("usage/spells",1);
	set("type","spells");
	set("effective_level",200);
	set("skill_class","moon");
}

int practice_skill(object me)
{	
	return notify_fail("幻念聆音无法练习。\n");
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
