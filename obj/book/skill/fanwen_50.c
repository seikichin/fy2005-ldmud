inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIR"五"NOR+HIY"色"+HIG"水"+HIM"晶"NOR, ({ "crystal"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "粒");
		set("no_split",1);
		set("long","\n"
"一粒五彩斑斓,散发着神奇光芒的水晶石，上面密密麻麻\n"
"刻着蝇头小字，似乎不是中土的文字。\n");
		set("value", 20000);
		set("material", "stone");
		set("no_drop",1);
		set("lore",1);
		set("skill", ([
            "name":         "fanwen",    
           "exp_required": 2000000,      
			"sen_cost":	5,	
			"difficulty":	5,	
            "max_skill":    50,      
		]) );
	}
    	::init_item();
}
