// shutdown.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player() ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" ){
		 notify_fail("只有 (arch) 以上的巫师才能重新启动" + "风云" + "\n");
		 return 0;
		 }

	message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	shutdown(0);
	return 1;
}
int help (object me)
{
write(funcall(#'read_file,"/help/cmds/arch/shutdown"));
        return 1;
}
 
