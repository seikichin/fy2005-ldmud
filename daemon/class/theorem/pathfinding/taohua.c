// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object qer;
	string qqq;

	int lvl=10;

	qqq="/d/maze/taoyuan-entry";

	extra = me->query_skill("pathfinding",1);

	if (extra < lvl && userp(me))
		return notify_fail("需要至少"+lvl+"级的天路引归。\n");
	
	if (me->is_fighting())
		return notify_fail("你现在正在战斗，无法使用天路引归。\n");
	
msg=HIM"\n"
"忽然间一阵风吹过，周围的桃花枝忽然移动起来。。。。\n"
"一阵天摇地转，你发现自己又回到了桃花林的进口。\n"NOR;

	if (base_name(environment(me))[0..19] == "/d/maze/taoyuan-maze")
	{
		tell_object(me,msg+"\n");
		qer=find_object(qqq);
		if (!qer)
			qer=load_object(qqq);
		me->move(qqq);
	}
	else
		tell_object(me,HIG"你失败了。\n"NOR);

	me->perform_busy(3);
	return 1;
}



