
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("木香",({"muxiang", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long", #'herb_desc);
	    set("unit","簇");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("material","herb");
	    
	    set("usage_type","herb");
	    set("heal_type","gin/10");
	    set("type","cure");
	    set("base_value",200);
	    set("level",20);
	    set("effect",500);
	    set("field","gin");
	    set("volumn",10);
	}
	set_amount(10);
}
