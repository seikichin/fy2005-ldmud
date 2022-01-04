// copy_file.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ){ 
		notify_fail("指令格式: copy_file 原档名 目标档名 \n");
		return 0;
		}

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = old_explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( copy_file(src, dst) )
		write("Ok.\n");
	else
		write("你没有足够的读写权利。\n");
	return 1;
}
 
int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/cp"));
    return 1;
}
 
