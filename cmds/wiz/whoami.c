// whoami.c

int main()
{
	write("你的 User ID = " + getuid(this_player()) + "\n" );
	write("你的 Effective User ID = " + geteuid(this_player()) + "\n" );
	return 1;
}

int help (object me)
{
   write(funcall(#'read_file,"/help/cmds/wiz/whoami"));
    return 1;
}
