// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: nuke living\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("找不到这个玩家。\n");
	message_vision("$N双手一举，一个焦雷将$n劈为飞灰！！\n",me,ob);
	ob->set("kickout_time",time());
	ob -> save();
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/nuke"));
   return 1;
}
