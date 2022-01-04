// dump.c (should be admin cmd?)
inherit F_CLEAN_UP;
#include <commands.h>
#include <driver_info.h>

private int driver_dumpallobj()
{
    write("Dumping to /OBJ_DUMP ... ");
    efun::dump_driver_info(DDI_OBJECTS);
    efun::dump_driver_info(DDI_OBJECTS_DESTRUCTED);
    write("done\n");
    return 1;
}
int main(object me,string arg)
{
	seteuid(geteuid(me));

    driver_dumpallobj();

	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/cmds/adm/dump"));
    return 1;
}
 
