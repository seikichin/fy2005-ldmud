// by tie@fengyun

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"番茄"NOR, ({ "tomato" }) );
	set_weight(80);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
        set("long", "一个红扑扑的大番茄.\n");
    	set("unit", "个");
        set("value", 50);
        set("food_remaining", 5);
    	set("food_supply", 60);
	}
	::init_item();
}
