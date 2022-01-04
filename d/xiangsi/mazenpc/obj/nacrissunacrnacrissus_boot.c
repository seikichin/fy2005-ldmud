#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
	set_name(HIW"清池法座"NOR, ({ "qingci" }) );
	set_weight(500);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "件");
    	set("material", "cloth");
    	set("value", 0);
    	set("no_get",1);
	}
	::init_boots();
}
