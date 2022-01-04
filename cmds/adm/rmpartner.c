#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    	string *files;
    	string wiz_status;
    	int i;
    	int size;

    	seteuid(getuid());

	if( me != this_player() ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" ){
		 return notify_fail("只有admin才能使用此命令。\n");
		 }
		
		
    	if(!arg || arg=="") { return notify_fail("格式不对！\n");}
    
    
    	files= get_dir(arg);
    	for(i=0; i<sizeof(files); i++) 
    	{
    	        size=sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c")
  	               	me->ccommand(sprintf("rm %s%s",arg,files[i]));
        }   	 	
    	return 1;
}

int help(object me)
{
        write(funcall(#'read_file,"/help/cmds/adm/rmpartner"));
    return 1;
}