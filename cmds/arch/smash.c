// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) { notify_fail("指令格式: smash living\n");return 0;}
	ob = present(arg, environment(me));
	if (!ob) { notify_fail("找不到这个生物。\n");return 0;}
	if (userp(ob)){
		 notify_fail("你不能对玩家使用此命令，请参看说明。\n");
		 return 0;
		 }
	
	message_vision("$N手一挥，一道闪电从天而降，将$n化为齑粉！！\n",me,ob);
	
	ob ->set_temp("last_damage_from", me);
	ob -> die();
	return 1;
}
 
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/smash"));
   return 1;
}
