// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	ob = users();	
	for (i=0;i<sizeof(ob);i++) {
		if (!ob[i] || !objectp(ob[i])) continue;
		if (!(i%10))
		ob[i]->ccommand("qsave");
	}
	write("共计"+ sizeof(ob)+"个对象，更新完毕。\n");
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/arch/qbox_save"));

    return 1;
}
