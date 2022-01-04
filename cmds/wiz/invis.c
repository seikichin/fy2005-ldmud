#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p") {
		me->set("wiz_invis",1);
		me->set("env/msg_mout","none");
		me->set("env/msg_min","none");
		me->set("env/invisibility",1);
		me->be_ghost(1);
		write("隐身成功。\n");
	}
	else {
		me->delete("wiz_invis");
		me->delete("env/invisibility");
		me->delete("env/msg_mout");
		me->delete("env/msg_min");
		me->be_ghost(0);
		write("取消隐身！\n");
	}
	return 1;
}
		
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/invis"));
	return 1;
}