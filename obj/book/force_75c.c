
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("大乘经", ({ "jinbook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long",
			"这是藏经阁中的一本藏书。\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"force",	
			"exp_required":		1000,		
			"sen_cost":		10,	
			"difficulty":	10,	
			"max_skill":	74		
		]) );
	}
	::init_item();
}
