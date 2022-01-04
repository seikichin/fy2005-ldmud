// File : /cmds/arch/cpstat.c
// annie 07.04.2003 dancing_faery@hotmail.com

#include <dbase.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_ANNIE;

int help(object me);

int main(object me, string arg)
{
	string tmp1,tmp2;
    	object ob, ob1;

	seteuid(geteuid(me));

	if (!arg){
		 notify_fail ("\n[USAGE]\n　　cpplayer [source] -to [destination]\n");
		 return 0;
		 }
    
    sscanf (arg, "%s -to %s", tmp1,tmp2);

	if (!tmp1 || !tmp2){
		 notify_fail ("\n[USAGE]\n　　cpplayer [source] -to [destination]\n");
		 return 0;
		 }
	
    	ob=present(tmp1, environment(me));
    	ob1=present(tmp2, environment(me));

	if (!ob || !ob1){
		 notify_fail ("\n[USAGE]\n　　cpplayer [source] -to [destination]\n");
		 return 0;
		 }

	if (!ob->is_character())
		if (!ob1->is_character()){
			 notify_fail ("Cpplayer：本指令的复制源与目标源必须是生物。\n");
			 return 0;
			 }
	
	if (!wizardp(ob1) || !userp(ob1)){
		 notify_fail("Cpplayer：本指令的目标源 "+ob1->query("id")+" 必须是巫师。\n");
		 return 0;
		 }
		
	tell_object(me,annie_skillcp(ob,ob1));
	tell_object(me,annie_attcp(ob,ob1));
	if (userp(ob) && userp(ob1))
		tell_object(me,annie_abilitycp(ob,ob1));
	return 1;
}


int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/cpplayer"));
    return 1;
}