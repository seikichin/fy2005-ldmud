//huntunforce.c

inherit SKILL;
void setup(){
	set("name","混沌功");
	set("type","force");
	set("usage/force",1);
	set("effective_level",130);
	set("difficulty",250);
	set("skill_class","beggar");
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
