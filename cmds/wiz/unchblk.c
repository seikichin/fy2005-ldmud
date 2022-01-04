// channel block command..
// Modified by Marz, 04/18/96


inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("指令格式：unchblk name \n");
    
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("这个人不在！\n");
	if (wizardp(ob)) return notify_fail("不能开启巫师的频道。\n");
	ob->delete("chblk_on");	
	tell_object(me, ({string})ob->query("name")+"的频道被开启了。\n");
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/unchblk"));
    return 1;
}

