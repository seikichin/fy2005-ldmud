// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file){
	if( !file ){
	return notify_fail("指令格式：edit 档名\n");
	}

//	if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

	seteuid(geteuid(me));
	write(resolve_path(me->query("cwd"), file));
	ed(resolve_path(me->query("cwd"), file));
	return 1;
}

int help(object me)
{
  write(funcall(#'read_file,"/help/cmds/adm/edit"));
    return 1;
}
