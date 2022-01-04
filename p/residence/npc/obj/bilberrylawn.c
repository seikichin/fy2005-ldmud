#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("越橘地", ({ "bilberry lawn"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(10000);
	set("unit", "片");
	set("desc", "一片星星点点缀着越橘的柔软草皮。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","h");
	set("outdoors",1);
	set("size",1);
set("tax",10);
set("score_tax",1);
	set("value", 100000);
	seteuid(getuid());
}

int is_container(){	return 1;}

int do_putitem(string arg)
{
	object me = this_player(),dest=this_object();
	string target, item;
	object obj, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什麽东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什麽东西？\n");

	if (present(target,environment(me)) != dest)
		return 0;
	
	write("请保持环境清洁，不要将垃圾望"+name()+"里乱丢。\n");
	return 1;
}

int reset_item_list(object dest)
{
	return 1;
}

int do_pick(string arg)
{
 	object me = this_player(),env=environment(me),ob=this_object(),herb,*inv;

	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (!arg)
		return 0;
	if (arg != "bilberry")
		return 0;
	if (query("pick_time") + 60 > time())
		return notify_fail("越橘地里只剩下一些绿绿的茎杆，饶过它们吧．．．\n");

	inv = all_inventory(ob);
	if (sizeof(inv))
		return notify_fail( "越橘地里已经有些越橘被摘下来了。\n");

	message_vision(CYN"\n$N从越橘地中摘下了一些小星似的越橘。\n"NOR, me);
	set("pick_time",time());
	herb = clone_object(__DIR__"bilberry.c");
	herb->set_amount(5);
	herb->move(ob);
	return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
