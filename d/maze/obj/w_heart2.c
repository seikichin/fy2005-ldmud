#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"玄铁"NOR, ({ "iron"}) );
        set_weight(500); 
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块银光闪闪的金属，是炼制兵器的辅助材料。\n");
                set("value", 2000);
                set("w-material",120);
        }
	::init_item();
}

