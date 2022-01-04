#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p") {
		me->be_ghost(1);
		write("你成功地变成了一只鬼！\n");
	}
	else {
		me->be_ghost(0);
		write("你又投胎做人了！\n");
	}
	return 1;
}
		
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/ghost"));
	return 1;
}