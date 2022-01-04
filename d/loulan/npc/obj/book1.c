inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIC"无敌宝鉴"NOR, ({ "wudi book","book" }));
	set_weight(600);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
        set("unit", "册");
    	set("long",
            "一束薄绢钉成的小册，封面上潦草的写着“无敌宝鉴之炼气篇”。\n");
        set("value", 7000);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_sell", 1);
    	set("material", "silk");
    	set("skill", ([
            "name":         "longlife-force",    
			"exp_required":		1000000,		
			"sen_cost":		10,	
			"difficulty":		20,	
			"max_skill":		50		
			]) );
	}
	::init_item();
}
