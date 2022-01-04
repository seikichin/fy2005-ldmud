// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player() ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") ){
		return  notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
		 }
	
	if( !arg || arg=="" ) {
		 return notify_fail("当前风云可登陆的最大人数为："+ LOGIN_D->query_max_users()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ){ 
		 return notify_fail("参见HELP格式说明。\n");
		 }
		
	seteuid(getuid());
	
	if (lvl>0 && lvl<10) {
		LOGIN_D->set_dummy_number(lvl-1);
		write(sprintf("\n当前每个ip可以连线人数设置为%d\n", lvl));
		return 1;
	}
		
	if( LOGIN_D->set_max_users(lvl)) {
		write(sprintf("\n进入游戏人数设置为%d	\n",lvl));
		return 1;
	} else{
 		 return notify_fail("上线人数设定失败。\n");
		 }
}

int help (object me)
{
   write(funcall(#'read_file,"/help/cmds/arch/loginlock"));
        return 1;
}
 
