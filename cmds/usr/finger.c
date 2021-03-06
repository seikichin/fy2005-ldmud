// finger.c
/*
(1) allow wizard (arch+) to be invisible to players.
(2) disable group finger for players --- no more dummy guess. we encourage role playing.
------	Modified by Silencer@fy4, 12/02/03
*/

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if (me->query_temp("timer/big_cmd")+2 > time())
		return notify_fail("此命令比较耗费系统资源，每秒只能执行一次。\n");
	else if (!wizardp(me))
		me->set_temp("timer/big_cmd",time());

	if( !arg ) {
		if( !wizardp(me) )
			return notify_fail("finger指令后面必须跟参数。\n");		
/*		if( ({int})me->query("sen") < 100 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
		{
			me->receive_damage("sen", 100);
			me->start_more("", FINGER_D->finger_all(0), 0);
		}
		else*/
			me->start_more("", FINGER_D->finger_all(1), 0);

	} else {
		if( ({int})me->query("sen") < 50 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("sen", 50);
		write( FINGER_D->finger_user(arg,(wizardp(me) || arg == ({string})me->query("id"))) );
	}
	return 1;
}


int help(object me)
{
  write("\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	finger [使用者姓名][0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令后跟使用者姓名,可显示有关某个玩家的连线, 权限等资料。\n"
"如果你要经常查阅一些玩家是否在线，建议使用friend指令。\n"
" \n"
"see also : who\n"
"\n"
"[0;1;37m────────────────────────────────[0m \n"
);
    return 1;
}
 
