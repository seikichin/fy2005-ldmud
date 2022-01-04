// medicine.c

inherit MEDICINE;
#include <ansi.h>
int eat_fun();

void create()
{
    	set_name(GRN"翠袖护心丹"NOR,({"cuixiudan","dan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
    	set("long",
"据说乃是“黄山翠袖”的独门灵药，以七十二种名药炼制七十二天而成，\n"
"色泽碧绿，护心养神，妙用无方。可以用来治疗2５0０点心神损伤。。\n");
	    	set("base_unit","颗");
	    	set("unit","包");
	    	set("base_weight",60);
        	set("base_value", 20000);
	    	set("type","cure");
		    	set("field","sen");	 
		    	set("effect",2500);   	
	    	set("heal_type","sen/2500");
	    	set("usage_type","pill");	
	    	set("use_func",(: eat_fun() :));
	    	set("volumn", 1);
	}
	set_amount(1);
}



int 	eat_fun() {
    	message_vision("$N咽下一粒翠袖护心丹，一股暖流护住丹田，气息陡然畅通起来。。。\n",this_player());
	return 1;
}
