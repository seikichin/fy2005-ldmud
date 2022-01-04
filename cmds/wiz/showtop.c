// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	seteuid(getuid());
	
	if (arg == "-refresh"){
		ob = users();	
		for (i=0;i<sizeof(ob);i++) {
			if (!ob[i] || !objectp(ob[i])) continue;
			if (!(i%10))
                         STATUS_D->compare_status(ob[i]);
		}
		write("共计"+ sizeof(ob)+"个对象，更新完毕。\n");
		return 1;
	}
		
	if (arg == "-rich")
	{
		output = STATUS_D->show_rich();
		me->start_more("", output, 0);		
	}	
	else if (arg == "-riddle")
	{
		output = STATUS_D->show_riddle();
		me->start_more("", output, 0);		
	}
	else {
		output = STATUS_D->show_top();
        me->start_more("", output, 0);
    }
    return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/showtop"));
    return 1;
}
