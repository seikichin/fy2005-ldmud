// finger.c
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

void init_finger() {
	if(!clonep()) {
		set("armor_type", TYPE_FINGER);
		set("armor_worn", WORN_FINGER);
	}
	::init_wear();
}
