// doggiesteps.c

inherit SKILL;

void setup()
{
	set("name","野狗步法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","beggar");
	set("dodge_msg", ({
		"但是$n身形飘忽，轻轻一纵，一招『野狗扑食』，举重若轻的避开这一击。\n",
		"$n身随意转，一式『野狗斜纵』，倏地往一旁挪开了三尺，避过了这一招。\n",
		"可是$n侧身一让，使出『野狗打滚』，$N这一招扑了个空。\n",
		"却见$n足不点地，一招『野狗上蹿』，往旁窜开数尺，躲了开去。\n",
		"$n身形微晃，使出『野狗下跳』，有惊无险地避开了$N这一招。\n",
		"$n身形往上一拔，一招『野狗左摇』，一个转折落在数尺之外。\n"
	}) );
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
