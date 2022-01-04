#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","唤狼术");
	set("skill_class","wolfmount");
	set("type","knowledge");
	set("difficulty",150);
	set("effective_level",150);
	set("no_refund",({"wolf-strike","wolf-curse"}));

}

/*
void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("summonwolf", 1);
    	if (s== 150 && me->query("class")=="wolfmount") {
       		tell_object(me,HIW "你对唤狼之术的了解有了一个飞跃！\n"NOR);
       		tell_object(me,HIW "你唤狼的个数增加了！\n"NOR);
       	} 
    	if (s== 180 && me->query("class")=="wolfmount") {
       		tell_object(me,HIW "你对唤狼之术的了解有了一个飞跃！\n"NOR);
       		tell_object(me,HIW "你可以在室内唤狼了！\n"NOR);
       }
}

int valid_learn(object me) {
		
    	if(me->query_skill("animal-training",1)<= me->query_skill("summonwolf",1))
    	{
		return notify_fail("唤狼术需要相同等级的训兽术作基础。\n");
	}
	return ::valid_learn(me);
}*/


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
