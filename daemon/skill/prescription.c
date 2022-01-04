
inherit SKILL;

void setup(){
	set("name","千金方");
	set("type","knowledge");
	set("skill_class","theorem");
	set("usage/theorem",1);
	set("effective_level",100);
	set("difficulty", 50);	
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3])
);
    return 1;
}
