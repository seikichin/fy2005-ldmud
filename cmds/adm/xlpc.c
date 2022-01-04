// chpasswd.c
// add by Karry@FY3
inherit F_CLEAN_UP;
#include <login.h>


void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        return Xlpc(arg);
        return 1;
}


int help(object me)
{
     write(funcall(#'read_file,"/help/cmds/adm/chpasswd"));   
    return 1;
}
