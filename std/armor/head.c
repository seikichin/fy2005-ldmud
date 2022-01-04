// head.c
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

void init_head() {
	if(!clonep()) {
		set("armor_type", TYPE_HEAD);
		set("armor_worn", WORN_HEAD);
	}
	::init_wear();
}
