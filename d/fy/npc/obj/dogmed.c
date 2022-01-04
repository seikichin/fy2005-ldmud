// medicine.c
inherit MEDICINE;

void create()
{
	set_name("狗皮膏药",({"gaoyao"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
    	set("long","一块狗皮膏药，可以用来贴在身上治疗40点心神损伤。\n");
    	set("unit","包");
    	set("base_unit","块");
    	set("base_weight",60);
    	set("type","cure");
    	set("base_value",20);
    	set("field","sen");
    	set("effect",40);
    	set("heal_type","sen/40");
    	set("usage_type","piece");	
    	set("volumn",5);
	}
	set_amount(5);
}


