// annie 07.2003


inherit SKILL;
void setup(){
	set("name","六灵暗识");
	set("skill_class","legend");
	set("type","knowledge");
	set("effective_level",150);
	set("difficulty",120);
}

int valid_learn(object me)
{
	if (me->query("class")!= "legend")
		return notify_fail("唯有铁雪弟子方能掌握六灵暗识之法。\n");
	return ::valid_learn(me);
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
