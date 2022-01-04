// reboot.c

#include <login.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player() ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" ){
		 notify_fail("只有 (arch) 以上的巫师才能重新启动" + "风云" + "\n");
		 return 0;
		 }

	seteuid(getuid());

	npc = clone_object(NPC_DEMOGORGON);
	npc->move(START_ROOM);
	npc->start_shutdown();

	write("Ok。\n");

	return 1;
}

int help (object me)
{
write(funcall(#'read_file,"/help/cmds/arch/reboot"));
        return 1;
}
 
