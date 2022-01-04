// begging.c

inherit SKILL;

void setup() {
	set("name","乞讨之术");
	set("type","knowledge");
	set("skill_class","beggar");
	set("difficulty",250);
	set("effective_level",200);
	set("no_refund",({"dragonstrike"}));
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
