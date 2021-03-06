// refresh.c

// 2009 FengYun
// Edit by hippo 2009.11
// 增加孝道支持

inherit SSERVER;

int exert(object me, object target, int amount)
{
        int skill=0;
        int m=0;
        
        if( target != me ) 
        	return notify_fail("你只能用内功收敛自己的心神。\n");

        if(amount == -1) amount = 20;
        else if(amount < 20 ) 
                return notify_fail("最少用二十内力。\n");

        if( ({int})me->query("force") < amount )
                return notify_fail("你的内力不够。\n");
        
        skill = ({int})me->query_skill("xiaodao",1);

		    if (skill >= 200) {m = 130;} 
	  		else if (skill >=150) {m = 122;}
	    	else if (skill >=100) {m = 115;}
				else if (skill >=50) {m = 108;}
				else {m=100;}

        me->receive_heal("sen", (10 + ({int})me->query_skill("force")/10)*amount/20*m/100 );
        me->add("force", -amount);

       message_vision("$N略一凝神，吸了口气，精神看起来清醒多了。\n消耗内力："+amount+" 恢复心神："+(10 + ({int})me->query_skill("force")/10)*amount/20*m/100+"\n", me);

       if( me->is_fighting() ) me->start_busy(1);

       return 1;
}
 
int help(object me)
{
    write("\n"
"指令格式 : exert recover [<耗费内力的量，预设值 ２0>]\n\n"
"运用内力来恢复心神。\n\n"
"平均恢复值＝ １０＋耗费内力＊有效内功等级／２００\n"
"相关命令 ：\n"
"	exert qi  （恢复体力）\n"
"	exert jing（恢复精力）\n"
        );
    return 1;
}