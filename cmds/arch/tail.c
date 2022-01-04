// tail.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	write(file);
	if( file_size(file)<0 ) { notify_fail("没有这个档案。\n");return 0;}
	write(tail(file));
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/tail"));
    return 1;
}
