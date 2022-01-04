// status.c
inherit F_CLEAN_UP;
#include <driver_info.h>

private int driver_status(string str)
{
    int opt;
     if (! is_root(previous_object()))
        return 0;

    switch(str || "")
    {
        case "":
            opt = DI_STATUS_TEXT_MEMORY;
            break;

        case "tables":
        case " tables":
            opt = DI_STATUS_TEXT_TABLES;
            break;

        case "swap":
        case " swap":
            opt = DI_STATUS_TEXT_SWAP;
            break;

        case "malloc":
        case " malloc":
            opt = DI_STATUS_TEXT_MALLOC;
            break;

        case "malloc extstats":
        case " malloc extstats":
            opt = DI_STATUS_TEXT_MALLOC_EXTENDED;
            break;

        default:
            return 0;
    }

    write(efun::driver_info(opt));
    return 1;
}


int main(object me,string arg)
{
	string msg;

	driver_status(arg);
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/status"));
    return 1;
}
 
