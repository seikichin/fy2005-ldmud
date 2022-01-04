// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("白棋子", ({ "go piece", "piece" }) );
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("long",	"纯汉白玉雕成的棋子儿。\n");
    	set("unit", "堆");
    	set("base_unit", "粒");
    	set("base_weight", 1);
    	set("base_value", 1);
    	set("volumn",1000);
	}
	set_amount(1000);
	init_throwing(50);
}
