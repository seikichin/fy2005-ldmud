#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("金缕衣", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "件");
    	set("value",1);
    	set("material", "cloth");
    	set("armor_prop/armor", 5);
	}
	::init_cloth();
}
