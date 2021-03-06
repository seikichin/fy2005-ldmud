// death_recover.c	此为巫师专用指令，用来恢复玩家因BUG而造成的死亡损失。
//		-- silencer@fy4

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object player;
	mapping death;
	string *lost_skill;
	int player_level, i;
	
	if( me!=this_player() ) return 0;
		
	if( !arg){
		 notify_fail("指令格式：death_recover 使用者\n");
		 return 0;
		 }

	player = find_player(arg);
	if (!player || !objectp(player)){
		 notify_fail("当前没有"+arg+"这个玩家。\n");
		 return 0;
		 }
		
	death = player->query("death");
	if (!death || !sizeof(death)){
		notify_fail("此人没有死亡纪录，无法用此命令恢复。\n");
		return 0;
		}

	write(sprintf("玩家的死亡纪录为%O\n",death));
		
	/*message_vision(HIW"$N将手中的法杖一挥，一道柔和的光芒从天而降，注入$n体内。\n\n"NOR,me,player); */
	
	tell_object(me,player->query("id")+"上次死亡时间为"+ctime(death["time"])+"。\n");
	tell_object(player,"上次死亡时间为"+ctime(death["time"])+"。\n");
	player->add("combat_exp",death["exp_lost"]);
		tell_object(player,"你损失的经验值全部恢复了，你的属性恢复正常。\n");
	player->delete("attr_apply");	// if they have more from previous death... well, lucky them.		
	
	/*log_file("BUG_RECOVER", sprintf(
		"%s 于 %s 替 %s 恢复一次死亡损失，(exp %d, pot %d)\n",
			me->query("id"), ctime(time()), player->query("id"),
			death["exp_lost"], death["pot_lost"]));*/
	
	player->delete("death");
						
	return 1;
}


int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/death_recover"));
    return 1;
}
