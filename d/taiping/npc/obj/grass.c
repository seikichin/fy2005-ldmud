inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("含羞草", ({ "touch-me-not","grass"}) );
	set_weight(50);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "株");
    	set("value", 1);
	}
}



