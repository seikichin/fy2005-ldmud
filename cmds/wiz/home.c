// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;

//	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
//		return notify_fail("你没有自己的工作室。\n");

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
//	me->move(user_path(geteuid(me)) + "workroom");
        me->move("d/wiz/jobroom"); 
        	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/home"));
    return 1;
}
