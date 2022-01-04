// summon command..

# include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("Syntax: Summon player id\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
	
	if (environment(ob)== environment(me))
		return notify_fail("这个人就在你的面前。\n");
	
	// moving
	message_vision("\n\n忽然$N身后跳出一人叫道：急、急，恶人谷老大找$N，死的活的都要。\n"
"说罢竟拉着$N跳上云端一溜烟地消失了。。\n\n", ob);
	tell_object(ob,"你觉得自己的身子一轻，不由自主地飞上了天，一准是哪位请你去了吧？\n\n");
	
	ob->move(environment(me));
        tell_object(me, "你把"+({string})ob->query("name")+"转移到你的面前.\n");
	tell_object(ob,"....原来是"+({string})me->query("name")+"找你有急事儿。\n");
	tell_room(environment(ob),({string})ob->query("name")+"从半空中飘飘悠悠地掉到地上。\n",({me,ob}));
	
     /*	log_file("static/SUMMON", sprintf("%s(%s) summoned %s(%s) to %s at %s。\n", me->name(1),
              me->query("id"), ob->name(1), ob->query("id"), base_name(environment(me)), ctime(time()) ) );*/
	
	return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/summon"));
    return 1;
}
