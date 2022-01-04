// cleanup.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where, *ob_list;
	int old_size, i;

	if (!str) { notify_fail("指令格式：cleanup 档名\n"); return 0;}

	str = resolve_path(me->query("cwd"), str);
	ob_list = children(str);
	old_size = sizeof(ob_list);
	ob_list->clean_up();
	for(i=0; i<sizeof(ob_list); i++)
		if( ob_list[i] && clonep(ob_list[i]) && !environment(ob_list[i]) )
			destruct(ob_list[i]);
	ob_list -= ({ 0 });
	printf("清除 %d 个物件。\n", old_size - sizeof(ob_list));
	return 1;
}

int help(object me)
{
	write(funcall(#'read_file,"/help/cmds/arch/cleanup"));
	return 1;
}

