// sheolmagic.c

inherit SKILL;
void setup(){
	set("name","夜叉通灵法");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("skill_class","demon");
	set("effective_level",200);
}       

int valid_learn(object me)
{
        return 1;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

