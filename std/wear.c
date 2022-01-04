// wear.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#pragma no_clone
inherit F_EQUIP;
inherit ITEM;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		 notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
		 return 0;
	}
}

void init_wear() {
	if(query("armor_prop") 
			&& !query("armor_prop/dodge") 
			&&  (weight() >= 300000)) {
		set("armor_prop/dodge", - weight() / 3000 );
	}
	if(!query("armor_prop")) {
		set("armor_prop/armor", 0);
	}	
}
