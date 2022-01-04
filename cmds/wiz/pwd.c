// pwd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		write("Cwd: " + ({string})me->query("cwd") +  "\n");
		write("Cwf: " + ({string})me->query("cwf") +  "\n");
		return 1;
	}
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/pwd"));
    return 1;
}
