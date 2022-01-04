// devil-spells.c

inherit SKILL;
void setup(){
	set("name","青冥魔咒");
	set("usage/spells",1);
	set("type","spells");
	set("effective_level",150);
	set("difficulty",200);
	set("skill_class","demon");
	
		
}	


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
