#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	int num, num1;
	
	if (me->query_temp("timer/lotto100")+ 2 > time())
		return notify_fail("此指令每２秒钟使用一次。\n");
		
	if (arg)	
		num = atoi(arg);
	
	if (!num || num >100)
		return notify_fail("你只能随机产生一个0到100之间的整数，格式：lotto number\n");
	
	num1 = random(num);
	
	message_vision(WHT"$N在0到"+ num + "之间掷出了"HIY + num1 + NOR+WHT"点。\n"NOR, me);
	me->set_temp("timer/lotto100", time());
	
	return 1;
}

int help(object me)
{
     write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 :		lotto <number>[0;32m	\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令让你随机产生一个０－ｎｕｍｂｅｒ之间的整数\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
);
    return 1;
}
