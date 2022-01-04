inherit SKILL;
void setup(){
	set("name","洗髓经");
	set("type","iron-cloth");
	set("skill_class","shaolin");
	set("effective_level",200);
	
	set("difficulty",200);
	set("usage/iron-cloth",1);
	set("bounce_ratio",8);
	set("ic_effect",50);
	
	set("absorb_msg", ({
        	"$N如击败革，一股大力从$n身上反弹回来。\n",
        	"$n全身似已脱胎换骨，一股弹力反击入$N。\n",
	}) );	
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
