// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("花衫", ({ "hua cloth" }) );
	set_weight(3000);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "件");
    	set("long", "一件轻纱织成的长衫\n");
    	set("material", "cloth");
    	set("value", 100);
    	set("armor_prop/armor", 3);
	}
	::init_cloth();
}
