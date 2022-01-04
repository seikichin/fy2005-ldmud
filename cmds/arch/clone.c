// clone.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/14/2001 by Daniel Q. Yu.
//

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file) {
	object obj;
	string err, msg;
	
	seteuid(geteuid(me));
	
	if(!file) {
		file = me->query("cwf");
	}
	if(!file) {
		 notify_fail("你要复制什麽物件？\n");
		 return 0;
	}
	
	file = resolve_path(me->query("cwd"), file);
	if(file[<2..<0] !=".c") {
		file += ".c";
	}
	me->set("cwf", file);
	if(file_size(file) < 0) {
		notify_fail("没有这个档案(" + file + ")。\n");
		return 0;
	}
	if(!find_object(file)) {
		err = catch(call_other(file, "???"));
		if(err){
			write("载入失败：" + err + "\n");
			return 1;
		}
	}
	err = catch(obj = clone_object(file));
	if(err){
		write("复制失败：" + err + "\n");
		return 1;
	}
	if(!objectp(obj)) {
		write("复制失败。\n");
		return 1;
	}
	/*log_file("CLONE_LOG", sprintf("(%s)\n%s cloned %s\n", ctime(time()), 
			me->query("name"), file));*/
	if(!stringp(msg = me->query("env/msg_clone"))) {
		msg = "$N在怀中摸索一番，拿出了$n。\n";
	}
	if(!obj->is_character() && obj->move(me)) {
		write(obj->query("name") + "复制成功，放在你的物品栏。\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	if(obj->move(environment(me))) {
		write(obj->query("name") + "复制成功，放在这个房间。\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	destruct(obj);
	 notify_fail("无法复制不能移动的物件(" + file + ")。\n");
	 return 0;
}

int help(object me) {
   write(funcall(#'read_file,"/help/cmds/arch/clone"));
    return 1;
}
