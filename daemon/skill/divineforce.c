// annie 6.27

inherit SKILL;

void setup(){
	set("name","破邪心经");
	set("type","force");
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","demon");
	set("effective_level",150);
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
