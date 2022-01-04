// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player() ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") ){
		 notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
		 return 0;
		 }
	if( !arg || arg=="" ){
		 notify_fail("指令格式：wizlock 巫师等级\n");
		 return 0;
		 }

	if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
	seteuid(getuid());
	if( LOGIN_D->set_wizlock(lvl) ) {
		write(sprintf("\n进入游戏等级限制在%s\n",chinese_number(lvl)));
		return 1;
	} else{
		 notify_fail("上线权限设定失败。\n");
		 return 0;
		 }
}

int help (object me)
{
write(funcall(#'read_file,"/help/cmds/arch/wizlock"));
        return 1;
}
 
