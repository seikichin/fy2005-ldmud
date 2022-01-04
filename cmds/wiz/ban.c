// ban.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		BAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else
			BAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->delete(site);
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能加入以 *, +, ? 结尾的地址。\n");
		else
			BAN_D->add_allow(site);	
	}
	else if (sscanf(arg, "-a - %s", site) == 1)
		BAN_D->delete_allow(site);
	else 
		write("指令格式：ban -参数 [+|- site]\n");

	return 1;

}

int help(object me)
{
	write(funcall(#'read_file,"/help/cmds/wiz/ban"));
	return 1;
}
