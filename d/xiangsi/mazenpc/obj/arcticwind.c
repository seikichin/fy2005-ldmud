#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"雪魄"NOR, ({ "arctic wind","wind"}) );
	set_weight(50);
	if( clonep() )
    	set_default_object(__FILE__);
	else 
	{
    	set("unit", "把");
    	set("lore",1);
    	set("long", "一把通体洁白，触手极凉的月牙弯刀。\n");
    	set("material", "ice");
    	set("ice_blade",2);
    	set("value",50);
	}
	::init_blade(35);
}

