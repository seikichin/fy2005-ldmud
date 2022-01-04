// cloth.c
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

void init_cloth() {
	if(!clonep()) {
		set("armor_type", TYPE_CLOTH);
		set("armor_worn", WORN_CLOTH);
		set("armor_prop/not_naked", 1);
	}
	::init_wear();
}

void init() {
	add_action("do_tear", "tear");
}

int do_tear(string str) {
	object ob;

	if(!id(str)) {
		return 0;
	}

	if(({string})query("material") != "cloth") {
		 notify_fail("你只能撕布料的衣服。\n");
		return 0;
	}
	
	if(({int})query("teared_count") >= 2) {
		notify_fail( name() + "的袖口，下□已经没有多馀的布可撕了。\n");
		return 0;
	}
	
	message_vision("$N从" + name() + "撕下数条布条。\n", this_player());
	add("teared_count", 1);
	ob = clone_object("/obj/item/bandage");
	if(objectp(ob)) {
		if(!ob->move(this_player())) {
			ob->move(environment(this_player()));
		}
	}
	return 1;
}
