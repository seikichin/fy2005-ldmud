#include <ansi.h>
// shout.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) ){
		 notify_fail("目前暂不开放玩家 shout。\n");
		 return 0;
		 }
	if (!arg) { notify_fail("你想要大叫什麽?\n"); return 0;}
	shout( HIW+me->name() + "纵声长啸：" + arg + "\n"NOR);
	write(HIW"你纵声长啸：" + arg + "\n"NOR);
	return 1;
}


int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/shout"));
    return 1;
}
 
