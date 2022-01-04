// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
//	write(__VERSION__+"\n");
	output = read_file("/doc/help/version.txt");
	printf("HTTP/1.0 302 Found\n\n"
         "Location: http://www.seikitin.com/\n\n"
         "Cloud Virtual Machine China. Local time: %s\n\n"
         "风云2005 LDmud, NATIVE mode, driver version %s\n\n",
         strftime("%c"), __VERSION__);
	write(output);
	return 1;
}
int help(object me)
{
  write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	version[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令会显示游戏目前所用的MudOS以及MudLIB版本.\n"
"\n"
"[0;1;37m────────────────────────────────[0m \n"
);
    return 1;
}
 
