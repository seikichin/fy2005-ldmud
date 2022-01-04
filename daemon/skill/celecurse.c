// cursism.c
inherit SKILL;

void setup() {
	set("name","通天降");
	set("type","cursism");
	set("usage/cursism",1);
	set("effective_level",200);
	set("difficulty",200);
	set("no_refund",({"qiankunwuxing"}));
	set("skill_class","yinshi");
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
