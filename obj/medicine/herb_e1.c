inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("金银花",({"jinyinhua", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一种不太常见的药草，配合药道心法可以用来解毒。\n");
	    set("unit","簇");
	    set("base_unit","棵");
	    set("base_weight",30);
	    
	    set("base_value",2000);
	    set("usage_type","herb");	
	    
	    set("material","herb");
	    set("level",50);
	    set("effect",1000);
	    set("type","depoison");
	    set("volumn",10);
	}
	set_amount(10);
}

