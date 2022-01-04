// cost.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed before, after;
	int stime, usertime, eval_cost;

	if( me != this_player() ) me = this_player();

	seteuid(getuid());
   	if(!arg) 
   		return notify_fail("指令格式：cost 指令 [参数 ....]\n");

    before = rusage();
	eval_cost = get_eval_cost();
	me->force_me(arg);
	eval_cost -= get_eval_cost();
	after = rusage();
	usertime = after["utime"] - before["utime"];
	stime = after["stime"] - before["stime"];
	printf("\n系统时间：%d 微秒\n使用者时间：%d 微秒\nEval cost：%d 单位\n",
		stime, usertime, eval_cost );
		
	return 1;

}

int help()
{
	write( "\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	cost <指令> [<参数> .... ][0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令让你测量另一个指令执行所需的时间。\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
""
	);
	return 1 ;
}
