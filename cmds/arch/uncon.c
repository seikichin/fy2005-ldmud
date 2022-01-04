// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) { notify_fail("指令格式: uncon living\n");return 0;}
	ob = present(arg, environment(me));
	if (!ob) { notify_fail("找不到这个生物。\n");return 0;}
	message_vision("$N手一挥，$n应声摔倒在地上！！\n",me,ob);
	ob -> unconcious();
	return 1;
}
 
int help(object me)
{
  write(funcall(#'read_file,"/help/cmds/arch/uncon"));
   return 1;
}
