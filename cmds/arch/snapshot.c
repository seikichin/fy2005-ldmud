
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) { notify_fail("指令格式: snapshot living\n");return 0;}
	ob = find_player(arg);
	if (!ob) { notify_fail("找不到这个生物。\n");return 0;}
	if (!userp(ob)){
		 notify_fail("你不能对非玩家使用此命令，请参看说明。\n");
		 return 0;
		 }
	"/feature/nada.c"->snapshot(ob);	
	write("Ok.\n");
	return 1;
}
 
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/snapshot"));
   return 1;
}
