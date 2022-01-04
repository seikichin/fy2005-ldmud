// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;
    
      
    if(!me->query("env/yesiknow")) { return notify_fail("这个指令已经被废除了！\n");}
		
	cmds = me->query_commands();
	write("你身上及四周的物品与所在的环境提供以下指令：\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(funcall(#'read_file,"/help/cmds/arch/localcmds"));
	return 1;
}

