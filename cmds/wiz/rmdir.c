// rmdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( rmdir(dir) )
		write("Ok.\n");
	else
		write("删除失败。\n");
	return 1;	
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/rmdir"));
	return 1;
}
