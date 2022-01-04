// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	if( !arg || arg=="" ) return help();

	me->delete("env/" + arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	unset <变数名>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令让你删除环境变数的设定。\n"
"修改变数设定请用 set 指令。\n"
"\n"
"至於有哪些环境变数可以设定，请见 help settings.txt。\n"
"\n"
"[0;1;37m────────────────────────────────[0m \n"
"\n"
""
	);
	return 1;
}
