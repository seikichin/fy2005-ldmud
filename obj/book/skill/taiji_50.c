
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("太极拳练功图", ({ "taijibook","太极拳练功图" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("long",
			"一幅太极拳练功图。\n");
		set("value", 70);
		set("material", "paper");
		set("no_shown",1);
		set("no_get",1);
		set("skill", ([
			"name": 		"taiji",	
			"exp_required":		2000,		
			"sen_cost":		20,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
	::init_item();
}
