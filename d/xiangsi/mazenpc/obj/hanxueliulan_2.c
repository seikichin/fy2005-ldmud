#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"『寒雪流岚·概略』"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));

		    	set("value", 1000);
                set("unit", "本");
                set("material", "paper");

                set("required_class","moon");

                set("teaching", "hanxueliulan");
		    	set("required_exp", 2400000);
		    	set("required_skill", "stormdance");
                set("required_skill_level",120);
		    	set("grade",2);
        }
}

