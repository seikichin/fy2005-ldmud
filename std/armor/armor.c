// armor.c
#pragma no_clone
#include <armor.h>
inherit WEAR;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		 notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
		 return 0;
	}
}

void init_armor() {
	if(!clonep()) {
		set("armor_type", TYPE_ARMOR);
		set("armor_worn", WORN_ARMOR);
		set("armor_prop/not_naked", 1);
	}
	::init_wear();
}
