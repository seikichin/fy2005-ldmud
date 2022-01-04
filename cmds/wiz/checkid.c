inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *u_list;
	int i,j;


	if(!stringp(arg))
		return notify_fail("你要找谁？\n");
	u_list=users();
	for(i=0; i<sizeof(u_list);i++)
	{
		if(u_list[i]->name(1)==arg)
	{
		write(arg+"=="+u_list[i]->query("id")+"\n");
		j=1;
	}
	}
	if(!j)
		write("没有发现这个人物。\n");
	return 1;
}       

int help(object me)
{
    write(funcall(#'read_file,"/help/cmds/wiz/checkid"));
    return 1;
}                              