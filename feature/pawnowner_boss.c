// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// Last Modified	- 02/16/2003 by silencer
// This file should be inherited by a pawnowner, who should have the following add_action
/* void init()
{
        ::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
}
*/

#define MAX_PAWN 9
#include <dbase.h>
#include <ansi.h>

int do_value(string arg)
{
	object ob;
	int value;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要拿什麽物品给当铺估价？\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other( MONEY_D, "arresthim", this_player() ):), 3);
		this_player()->perform_busy(2);
		return notify_fail("你感觉有点不对劲，好像周围有人紧紧地盯住了你。\n");
	}
	if( ob->query("money_id") )
		return notify_fail("这是「钱」，你没见过吗？\n");
	if( ob->query("generate_item") )
		return notify_fail("这不是ｂｏｓｓ物品，我这里不收，去卖香菱吧。\n");

	value = ob->query("level_required");   //add by ldb 价值基数相当于装备级别
	if( !value || value < 4) printf("%s并不值几文钱。\n", ob->query("name"));
	else 	{
//		value = value * 10000   //add by ldb 价值=相当装备级别的gold
		printf("%s价值%s。\n 如果卖断(sell)，可以拿到%s。\n",
			ob->query("name"), 
			MONEY_D->money_str(value * 10000),
//			MONEY_D->money_str(value * 25 / 100), 
			MONEY_D->money_str(value * 80 / 100 * 10000));
		if (ob->query("item_damaged"))
	       		tell_object(this_player(),"不过此物品已经损坏了，在修好之前恐怕没人会感兴趣的。\n");
	}
	return 1;
}


int do_sell(string arg)
{
	object ob;
	int value,old, amount;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能卖物品。\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other( MONEY_D, "arresthim", this_player() ):), 3);
		this_player()->perform_busy(2);
		return notify_fail("你感觉有点不对劲，好像周围有人紧紧地盯住了你。\n");
	}
	if( ob->query("money_id") )	return notify_fail("你要卖「钱」？\n");
	if( ob->query("generate_item") )
		return notify_fail("这不是ｂｏｓｓ物品，我这里不收，去卖香菱吧。\n");
    if (ob->query("no_sell")|| ob->query("no_drop")||ob->query("no_transfer"))
	       	return notify_fail("你不可以卖这样东西。\n");
	
	value = ob->query("level_required");
        if( value<4)       	
        	 return notify_fail("这样东西并不值很多钱。\n");
	if (ob->query("item_damaged"))
		return notify_fail(this_object()->name()+"说：“本店不收购坏了的东西。”\n");
		
// to make life more realistic
        if( (({int})this_object()->query("richness")) < (value*80/100*10000))
                return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
        this_object()->add("richness",-(value*80/100));

	if (this_player()->query_temp("timer/sale")+2 > time())
		return notify_fail(this_object()->name()+"堆笑道：“客官稍候，马上就来招呼！”\n");
	this_player()->set_temp("timer/sale",time());

	message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
		this_player());
	old = this_object()->query_with_slash("vendor_goods."+base_name(ob));
// modified combined and throwing items. If the amount>base volumn, then calculate it and put
// in inventory, otherwise disgard it.	-- by Silencer 12/19/2002
	amount = ob->query("base_unit")? 
		 ob->query_amount()/ob->query_volumn():
		 1;
	if (amount)
		this_object()->set_with_slash("vendor_goods."+base_name(ob), old + amount);
	
	MONEY_D->pay_player(this_player(), value  * 80 / 100 * 10000);
	ob->move(VOID_OB);
	destruct(ob);
//	this_player()->start_busy(1);	用timer代替busy，每一秒钟交易一次。
	return 1;
}