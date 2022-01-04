// call.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname, func, param, euid;
	object obj;
	mixed *args, result;
	int i,r1;
        
//	if(!me->query("env/FYnocall")) { notify_fail("这个指令已经被废除了！\n"); return 0;}
	if( arg ) {
		//-> Added by neon :P	
	    	arg = remove_ansi(arg);

		
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( ({string})SECURITY_D->get_status(me) != "(admin)" ){
				 notify_fail("你不能设定自己的 euid。\n");
				 return 0;
				 }
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player()) );

		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 ){
			notify_fail("指令格式：call 物件->函数( 参数, ... )\n");
			return 0;
			}
	} else{
		 notify_fail("指令格式：call 物件->函数( 参数, ... )\n");
		 return 0;
		 }

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visiblep(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) { notify_fail("找不到指定的物件。\n");return 0;}

	obj->set("last_call_from",me->query("id"));
	
	if( userp(obj) ){
		if( obj != me ) log_file("static/CALL_PLAYER",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
		if (obj != me && (func == "set" || func == "delete" || func == "add" 
			|| func == "set_temp" || func == "add_temp" || func == "delete_temp")
			|| func == "set_skill" )
			CHANNEL_D->do_sys_channel(
			"info",sprintf("%s(%s)对%s(%s)进行了某些修改。", 
			me->query("name"),me->query("id"),obj->query("name"),obj->query("id")));
	} else if( !master()->valid_write( base_name(obj), me, "set" ) ){
		 notify_fail("你没有直接呼叫这个物件的函数的权力。\n");return 0;}
	else log_file("static/CALL_OTHER",
			sprintf("%O(%O) call %O(%O)->%O(%O) on %O\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,ctime(time()) ) );

	args = old_explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
	    
		// This removes preceeding blanks and trailing blanks.
		args[i]=trim(args[i],3);
	//	parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) )   continue;
        
		//args[i] = restore_variable(args[i]);
	}

	//args = ({  }) + args;

	result=call_other(obj, func,args...);

	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("call %O->%s(%s) = %O\n", obj, func, 
		implode(args[0..sizeof(args)-1], ", "), result);

	write("呼叫结束\n");
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/call"));
    return 1;
}
