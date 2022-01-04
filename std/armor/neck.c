// neck.c
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

void init_neck() {
	if(!clonep()) {
		set("armor_type", TYPE_NECK);
		set("armor_worn", WORN_NECK);
	}
	::init_wear();
}
