// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(RED"心字罗衣"NOR, ({ "redskirt" }) );
	set_weight(3000);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "件");
    	set("long", "一件心字香熏成的罗衣，穿上后香风阵阵。\n");
    	set("material", "cloth");
        set("value", 1000);
         set("armor_prop/armor", 3);
    	set("female_only", 1);
	}
	::init_cloth();
}
