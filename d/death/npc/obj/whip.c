// TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name(HIR"铁索"NOR, ({ "tiesuo" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 500);
    	set("rigidity",1000);
                set("material", "skin");
        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
        }
        ::init_whip(15);
}

