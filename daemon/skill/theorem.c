
inherit SKILL;

void setup(){
	set("name","无有之术");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("no_refund","attr");
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3])
);
    return 1;
}
