
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("白石", ({ "pebble","cobble","stone" }) );
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("long",	"一堆白色的小石头。\n");
    	set("unit", "堆");
    	set("base_unit", "粒");
    	set("base_weight", 100);
	}
	set_amount(1);
	::init_throwing(10);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	victim->add_temp("annie/pebble", 1);
	if (victim->query_temp("annie/pebble") < 4)
		victim->set_temp("body_print", "他的头上肿起了"+chinese_number(victim->query_temp("annie/pebble"))+"个小包。");
	else
		victim->set_temp("body_print", "他的头上密密麻麻肿起了一片丘陵也似的小包。");
	return "只听啪嗒一声，白石在$n额上砸出了一个小鼓包。\n";
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
