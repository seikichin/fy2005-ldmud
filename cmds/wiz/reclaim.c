// reclaim.c

int main(object me, string arg)
{
	int mem;

	write("......正在清除无用变数。\n");
	garbage_collection("/GCLOG", 1);
	return 1;
}

int help(object me)
{
write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m巫师指令格式 : 	reclaim[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"用处 : 将存在於记忆体里无用的变数清除掉, 以减少记忆体的使用。\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
""
     );
     return 1;
}
