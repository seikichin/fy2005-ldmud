// staff.c


#include <weapon.h>
inherit STAFF;

void create() {
	set_name("登山棍", ({ "staff" }) );
	set_weight(2000);
	if(clonep())
    	set_default_object(__FILE__);
	else {
    	set("unit", "根");
    	set("long", "这是一把看起相当普通的木棍。");
    	set("value", 100);
    	set("material", "wood");
    	set("wield_msg", "$N把$n紧紧地握在手中。\n");
    	set("unwield_msg", "$N松开了手中的$n。\n");
    	set("climb",1);
	}
    ::init_staff(15);
}
