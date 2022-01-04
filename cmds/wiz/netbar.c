// netbar.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		NETBAR_D->print();
	else if (arg == "-s") {
		NETBAR_D->netbar_switch();	
	}	
	else if (sscanf(arg, "-y + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能使用以 *, +, ? 结尾的地址。\n");
		else
			NETBAR_D->add(site);
	}
	else if (sscanf(arg, "-y - %s", site) == 1) {
		NETBAR_D->delete(site);
	}
	else if (sscanf(arg, "-n + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能使用以 *, +, ? 结尾的地址。\n");
		else
			NETBAR_D->add_ban(site);
	}
	else if (sscanf(arg, "-n - %s", site) == 1) {
		NETBAR_D->delete_ban(site);
	}
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能使用以 *, +, ? 结尾的地址。\n");
		else
			NETBAR_D->add_all(site);
	}
	else if (sscanf(arg, "-a - %s", site) == 1) {
		NETBAR_D->delete_all(site);
	}	
		
	else 
		write("请参看指令格式	netbar -参数 [+|- site]\n");

	return 1;
	
}

int help()
{
write(funcall(#'read_file,"/help/cmds/wiz/netbar"));
	return 1;
}