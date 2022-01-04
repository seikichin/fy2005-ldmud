// profile.c

int main(object me, string arg)
{
	seteuid(geteuid(me));

	PROFILE_D->make_profile(arg);
	write("Result written to /PROFILE\n");

	return 1;
}
int help (object me)
{
    write(funcall(#'read_file,"/help/cmds/adm/profile"));
        return 1;
}
 
