#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player() ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") ){
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
		 }
	
	if( !arg || arg=="" ) {
	 return notify_fail("当前Quest的额外奖励为："+ QUESTS_D->query_holiday()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) {
		return notify_fail("参见HELP格式说明。\n");		 
		 }
		
	seteuid(getuid());
	
	if (lvl>=0 && lvl<=900) {
	QUESTS_D->set_holiday(lvl);
		write(HIR"\n当前每个Quest的奖励为原来的"+ (lvl+100)+"%，有效期持续到系统重启或再次设置。\n"NOR);
		CHANNEL_D->do_sys_channel("info","天机使命（Quest）的经验/能力奖励现在设置为 "+(lvl+100)+"％，大家加油啊！");
		log_file("QBONUS_UPDATE_LOG", 
					sprintf("(%s)%s 改动QUEST奖励到%d。\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					lvl
				));
		return 1;
	}
		
	return notify_fail("你只能设置0-900之间的数字。\n");	 
}

int help (object me)
{
        write(funcall(#'read_file,"/help/cmds/arch/holiday_bonus"));
        return 1;
}
 
