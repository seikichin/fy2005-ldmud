// callouts.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *info;
	int i;
	string output;

	output = sprintf("%-30s %-20s %5s \n", "物件", "函数", "延迟时间"); 
	if( arg && arg!="" )
		info = filter(call_out_info(), (: $1[1]==$2 :), arg);
	else
		info = call_out_info();

	for(i=0; i<sizeof(info); i++)
		output += sprintf("%-30O %-20s %5d \n",
			info[i][0], info[i][1], info[i][2] );

	me->start_more("", output, 0);
	return 1;
}

int help()
{
write(funcall(#'read_file,"/help/cmds/arch/callouts"));
	return 1;
}
