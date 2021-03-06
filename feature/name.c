// name.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/20/2001 by Daniel Q. Yu.
//			* Add long_spring_day, long_spring_night etc.

#include <ansi.h>
#include <dbase.h>

nosave string *my_id;

string *my_id()
{
	return my_id;
}

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

int id(string str)
{
	string *applied_id;

	if( this_player() && !this_player()->visiblep(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) ) 
		if( member_array(str, applied_id)!=-1 )
			return 1;
		else
			return 0;
			
	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
		return 1;
	else
		return 0;
}

string get_id()
{
	string *applied_id;
	
	if(pointerp(applied_id=query_temp("apply/id"))
		&& sizeof(applied_id))
		return applied_id[0];
	else
		return query("id");
}
		
	

string *parse_command_id_list() {
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw) {
	string str, *mask;
	
	if(function_exists("query",this_object()) == 0)
	{
		return file_name(this_object());
	}
	
	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else {
		if( stringp(str = query("name")) )
			return str;
		else
			return file_name(this_object());
	}
}

varargs string short(int raw) {
	string title, nick, str, *mask, *applied_id;
	
	if(!stringp(str = query("short")) )
		str = name(raw) + "(" + capitalize(
				pointerp(applied_id = query_temp("apply/id")) && sizeof(applied_id) ? applied_id[sizeof(applied_id) -1] : query("id"))
				+ ")";

	if(!this_object()->is_character() /*|| (pointerp(applied_id) && sizeof(applied_id))*/) {
		return str;
	}
	
	if(!raw && sizeof(mask = query_temp("apply/short"))) {
		str = mask[sizeof(mask)-1];
	} else {
		if( stringp(nick = query("nickname")) )
			str = sprintf("???%s???%s", nick, str);

		if( stringp(title = query("title")) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);
	}

	if( !raw ) {
		if( this_object()->is_ghost() ) str = HIB "(??????) " NOR + str;
		if( query_temp("netdead") ) str += HIG " <?????????>" NOR;
	//	if( in_input() ) str += HIC " <???????????????>" NOR;
	//	if( in_edit() ) str += HIY " <???????????????>" NOR;
		if( interactive(this_object())
		&&	query_idle( this_object() ) > 120 ) str += HIM " <?????????>" NOR;
		if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
		if( query_temp("disable_inputs")) str += HIR + query("disable_type") + NOR;
		if (query_temp("condition_type")) str += HIW + query_temp("condition_type") +NOR;	
		if (this_object()->is_fighting())		str += WHT"	** ????????? **"NOR;
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;
	
	if(!raw && sizeof(mask = query_temp("apply/long"))) {
		str = mask[sizeof(mask)-1];
	} else {
		switch(NATURE_D->get_season()) {
			case 1:
				str = NATURE_D->is_day_time() ? query("long_spring_day") : query("long_spring_night");
				if(!stringp(str)) {
					str = query("long_spring");
				}
				break;
			case 2:
				str = NATURE_D->is_day_time() ? query("long_summer_day") : query("long_summer_night");
				if(!stringp(str)) {
					str = query("long_summer");
				}
				break;
			case 3:
				str = NATURE_D->is_day_time() ? query("long_fall_day") : query("long_fall_night");
				if(!stringp(str)) {
					str = query("long_fall");
				}
				break;
			case 4:	
				str = NATURE_D->is_day_time() ? query("long_winter_day") : query("long_winter_night");
				if(!stringp(str)) {
					str = query("long_winter");
				}
				break;
			default:
				str = NATURE_D->is_day_time() ? query("long_day") : query("long_night");
				if(!stringp(str)) {
					str = query("long");
				}
				break;
		}
		if(!stringp(str)) {
			str = NATURE_D->is_day_time() ? query("long_day") : query("long_night");
			if(!stringp(str)) {
				str = query("long");
				if(!stringp(str)) {
					str = short(raw) + "???\n";
				}
			}
		}
	}

	if(stringp(extra = this_object()->extra_long())) {
		str += extra;
	}

	return str;
}

