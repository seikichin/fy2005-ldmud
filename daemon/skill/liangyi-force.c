// taijiforce.c

inherit SKILL;

void setup(){
	set("name","两仪心法");
	set("type","force");
	set("difficulty",250);
	set("usage/force",1);
	set("effective_level",100);
	set("skill_class","task");
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
