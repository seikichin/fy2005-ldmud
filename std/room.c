// room.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

//	11/10/2002	removed room_item_force_refresh to save system load, only 5-6 rooms use that one.
//	11/13/2002	removed return_home to simplify code.
//	11/19/2002	added a function to check if there is user in room.
//			-- by silencer@fy4 
//	3/12/2003	Major change in room, removed all door-related function to DOOR_ROOM
//			-- by silencer@fy4 
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <dbase.h>

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		 notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
		 return ;
	}
}

int query_max_encumbrance() { 
	return 100000000000; 
}

object make_inventory(string file) {
	object ob;
	
	ob = clone_object(file);
	if(objectp(ob)) {
		ob->move(this_object());
		ob->set("startroom", base_name(this_object()));
	}
	return ob;
}

void reset() {
	mapping ob_list, ob;
	string *list;
	int i,j;
	object *inv;
	
    	// I put this one here to get rid the function of trash collecting...Tie
    	// since the quest feature, rooms hardly get swapped out.
	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--) {
		if(!inv[i]->is_character() 
				&& inv[i]->query("startroom") !=base_name(this_object()) 
				&& !inv[i]->query("no_reset")) {
			destruct(inv[i]);
		}
	}

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is 
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//
	set("no_clean_up", 0);
	ob_list = query("objects");
	if(!mappingp(ob_list)) {
		return;
	}
	if(!mappingp(ob = query_temp("objects"))) {
		ob = m_allocate(sizeof(ob_list));
	}
	
	list = keys(ob_list);
	for(i=0; i<sizeof(list); i++) {
		// Allocate an array if we have multiple same object specified.
		if(undefinedp(ob[list[i]]) && intp(ob_list[list[i]]) && ob_list[list[i]] > 1) {
			ob[list[i]] = allocate(ob_list[list[i]]);
		}
		switch(ob_list[list[i]]) {
			case 1:
//  ??????????????????????????????????????????
				if(!ob[list[i]]) {
					ob[list[i]] = make_inventory(list[i]);
					continue;
				}

/* ????????????????????????????????????????????????--- ????????????????????????????????????room?????? Silencer??? 				

				else if (  query("refresh_all_items") &&  environment(ob[list[i]]) != this_object() ) {
					ob[list[i]] = make_inventory(list[i]);
					continue;
				}					*/
				
// ??????NPC????????????????????????????????????NPC?????????
// random_move???????????? std/char/npc ?????????.??????Riddle NPC????????????
// pursuer ????????????????????????NPC?????????return_home????????????--- Silencer 				
/*				if(environment(ob[list[i]]) != this_object() 
						&& ob[list[i]]->is_character()) {
					if(!ob[list[i]]->return_home(this_object())) {
						add("no_clean_up", 1);
					}
				}*/
				break;
			default:
				for(j=0; j<ob_list[list[i]]; j++) {
					// If the object is gone, make another one.
					if( !objectp(ob[list[i]][j]) ) {
						ob[list[i]][j] = make_inventory(list[i]);
						continue;
					}
/*-> Added by neon to refresh items in room ground
					else if ( query("refresh_all_items") &&  environment(ob[list[i]][j]) != this_object() ) {
						ob[list[i]][j] = make_inventory(list[i]);
						continue;
					}
<- End of refreshing items					*/
					// Try to call the wandering npc come back here.
/*					if(environment(ob[list[i]][j]) != this_object()
							&& ob[list[i]][j]->is_character()){
						if(!ob[list[i]][j]->return_home(this_object())){
							add("no_clean_up", 1);
						}
					}*/
				}
				break;
		}
	}
	set_temp("objects", ob);

}


// ????????????????????????userp

int usr_in()
{
	object *inv = deep_inventory(this_object());
	int i = sizeof(inv);
	
	while (i--) {
		if(userp(inv[i])) return 1;
	}
	return 0;
}

void setup()
{
    	seteuid(getuid());
    	this_object()->reset();
}

string long() {
	string str;
	if(NATURE_D->is_day_time()) {
		str = query("long_day");
	} else {
		str = query("long_night");
	}
	if(!stringp(str)) {
		str = query("long");
		if(!stringp(str)) {
			str = query("short") + "???\n";
		}
	}

	return str;
}

int valid_leave(object me, string dir)
{
	return 1;
}
int is_room()
{
	return 1;
}

