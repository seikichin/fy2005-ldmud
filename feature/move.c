// move.c
// Copyright (C) 1995 - 2001, by Daniel Q. Yu and Tie Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/22/2001 by Daniel Q. Yu.
//

#include <move.h>
#include <dbase.h>
#include <room.h>
#include <ansi.h>

#define MAX_CARRY 29
nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { 
	return encumb; 
}

nomask int over_encumbranced() { 
	return encumb > max_encumb; 
}

nomask int query_max_encumbrance() { 
	return max_encumb; 
}

nomask void set_max_encumbrance(int e) { 
	max_encumb = e; 
}

nomask void add_encumbrance(int w) {
	encumb += w;
	if(encumb < 0) {
		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
		encumb=0;
	}
	if(encumb > max_encumb) {
		this_object()->over_encumbrance();
	}
	if(environment()) {
		environment()->add_encumbrance(w);
	}
}

void over_encumbrance() {
	if(!interactive(this_object())) {
		return;
	}
	tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { 
	return weight; 
}

nomask void set_weight(int w) {
	if(!environment()) {
		weight = w;
		return;
	}
	if(w!=weight) environment()->add_encumbrance( w - weight );
	weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { 
	return weight + encumb; 
}

varargs int move(mixed dest, int silently) {
    object ob, env, *inv;

	// If we are equipped, unequip first.
	if(query("equipped") && !this_object()->unequip()) {
		 notify_fail("你没有办法取下这样东西。\n");
		 return 0;
	}
	
	// Find the destination ob for moving.
	if(objectp(dest)) {
		ob = dest;
	} else if(stringp(dest)) {
		call_other(dest, "???");
		ob = find_object(dest);
		if(!ob) {
			          notify_fail("move: destination unavailable.\n");
			           return 0;
		}
	} else {
		 notify_fail(sprintf("move: invalid destination %O.\n", dest));
		 return 0;
	}
	
	// Check if the destination ob can hold this object.
	// Beforce checking it, we check if the destination is environment of
	// this_object() (or environment of its environment). If it is, then
	// this could be like get something from a bag carried by the player.
	// Since the player can carry the bag, we assume he can carry the this
	// object in the bag and encumbrance checking is unessessary.
	env = this_object();
	while(env = environment(env)) {
		if(env==ob) {
			break;
		}
	}
	if(!env && ({int})ob->query_encumbrance() + weight() > ({int})ob->query_max_encumbrance()) {
		if(ob==this_player()) {
			 notify_fail(this_object()->name() + "对你而言太重了。\n");
			 return 0;
		} else {
			notify_fail(this_object()->name() + "对" + ob->name() + "而言太重了。\n");
			return 0;
		}
	}
	// check if player carrying too much!
	if(interactive(ob) && living(ob)) {
		inv = all_inventory(ob);
		if(sizeof(inv) >= MAX_CARRY) {
			tell_object(ob,"你身上已经带着太多东西了．\n");
			 notify_fail(ob->name()+"身上已经带着太多东西了．\n");
			 return 0; 
		}
	}
	// Move the object and update encumbrance
	if(environment()) {
		if(environment()->invalid_leave(this_object())) {
			notify_fail("move: object can't leave.\n");
			return 0; 
		}
		environment()->add_encumbrance( - weight());
	}
	move_object(this_object(),ob);
	ob->add_encumbrance(weight());
    return 1;
}

void remove()
{
	object default_ob;

	if( !previous_object()
	||	base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() can only be called by destruct() simul efun.\n");
       
	if( userp(this_object())) {
//		log_file("destruct", sprintf("%O attempt to destruct user object %O (%O)\n",previous_object(1), this_object()->query("id"), ctime(time())));
//		error("你(" + euid + ")不能摧毁其他的使用者。\n");
	} else if( this_object()->query("equipped")) {
		if(	!this_object()->unequip() )
			log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
	}

	// We only care about our own weight here, since remove() is called once
	// on each destruct(), so our inventory (encumbrance) will be counted as
	// well.
	if(this_object()->query("unique_amount")) {
		ITEM_D->remove_unique(this_object());
	}
	if( environment() )	environment()->add_encumbrance( - weight() );
	if( default_ob = this_object()->query_default_object() )
		default_ob->add("no_clean_up", -1);
}


