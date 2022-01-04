// medicine.c

#include <ansi.h>
inherit MEDICINE;

void create()
{
	set_name("虎骨丸",({"hugu"}));
        if(clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long","一颗虎骨丸，可以用来治疗50点精力损伤。\n");
    	set("unit","盒");
    	set("base_unit","颗");
    	set("base_weight",60);
    	set("base_value", 300);
    	set("field","gin");
    	set("type","cure");
    	set("effect",50);
    	set("heal_type","gin/50");
    	set("usage_type","pill");
    	set("volumn",5);	
	}
	set_amount(5);
}
