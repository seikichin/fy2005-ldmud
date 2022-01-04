// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;

	object obj;

	if (!arg) { notify_fail("指令格式 : dest 物件之名称或档名\n" ); return 0;}

	if( sscanf(arg, "-%s %s", option, target)!=2 ) target = arg;
	if( option == "r" && ({string})SECURITY_D->get_status(me)=="(admin)" ){
		seteuid(ROOT_UID);
	}
	else{
		seteuid(geteuid(me));
      }
	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	
	if (!objectp(obj)){ 
		notify_fail("没有这样物件....。\n");
		return 0;
		}

	if ( userp(obj) &&  ({string})SECURITY_D->get_status(me)!="(admin)" ){
		notify_fail("你没有摧毁对方的权限。\n");
		return 0;
		}
	
	tell_object( me, sprintf("摧毁物件： %O\n", obj));
	
	msg = "";
	
	if( environment(me)==environment(obj) )
	{
		if( !stringp(msg = me->query("env/msg_dest")) )
			msg = "$N召唤出一个黑洞，将$n吞没了。\n";
		message_vision(msg + "\n", me, obj);
	}
	else {
		msg = "$N召唤出一个黑洞，把周围吞没了。\n";
		message_vision(msg + "\n", me);
	}
	
	destruct(obj);
	if(obj) 
		write("你无法将这个物件摧毁。\n");
	else 
		write("物件摧毁成功。\n");

	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/cmds/arch/dest"));
    return 1;
}
