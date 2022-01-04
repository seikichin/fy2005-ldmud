// channel block command..
// Modified by Marz, 04/18/96
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
	{
	if(CHANNEL_D->query("block_chat"))
		write("chat	off\n");
	else    write("chat	on\n");
        if(CHANNEL_D->query("block_rumor"))
                write("rumor	off\n");
        else    write("rumor	on\n");
        if(CHANNEL_D->query("block_fy"))
                write("fy	off\n");
        else    write("fy	on\n");
        if(CHANNEL_D->query("block_new"))
                write("new	off\n");
        else    write("new	on\n");

	return 1;

	}
   if( arg == "rumor" || arg == "chat" || arg == "fy" || arg == "new")
	{
	CHANNEL_D->set_block(arg,0);
	EMOTE_D->set_block(arg,0);
	}
	else
	return notify_fail(" channel_name 只可以是 rumor, chat, fy,和new中的一个。\n"); 

	tell_object(me, arg+"频道被开启了。\n");
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/on"));
    return 1;
}
