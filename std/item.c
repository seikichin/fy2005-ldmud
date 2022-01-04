// item.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;


void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		 notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
		 return ;
	}
}

void init_item() {

}
