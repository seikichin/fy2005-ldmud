// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	if(me->query_temp("proprop") && me->query_temp("block_msg/all")>=1)
	{
		me->add_temp("proprop",-1);
		me->add_temp("block_msg/all",-1);
		write(CLR);
		write("屏幕输入恢复正常状态，请继续工作：\n");
	} else
		write("你没有使用过BOSS指令。\n");
		
	return 1;
}

int help(object me)
{
     write("指令格式: bossgone  \n"
"\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	指令格式: bossgone  [0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令让你(玩家)在老板走后恢复正常风云游戏。\n"
"\n"
"有关指令：boss\n"
"\n"
"[0;1;37m────────────────────────────────[0m \n"
);
    return 1;
}
