#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIY"金边长袍"NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "件");
    	set("material", "cloth");
    	set("armor_prop/armor", 1);
	}
	::init_cloth();
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

