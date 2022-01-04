inherit SKILL;

void setup(){
	set("name","碎玉神罡");
	set("type","force");
	set("usage/force",1);
	set("skill_class","berserker");
	set("effective_level",150);
	set("difficulty",200);
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
