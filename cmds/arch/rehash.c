// rehash.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ){
		 notify_fail("指令格式：rehash 路径\n");
		 return 0;
		 }

	if( arg[strlen(arg)-1]!='/' ) arg += "/";
	printf("arg: %O \n",arg);
	if(  file_size(arg)!=-2 ){
		 notify_fail("没有这个目录！\n");
		return 0;
		}

	write("更新指令表：" + arg + "\n");
	COMMAND_D->rehash(arg);
	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/cmds/arch/rehash"));
	return 1;
}
