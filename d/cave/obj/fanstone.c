// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
    set_name("石头", ({ "石头","stone"}));
	set_weight(600);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
        set("unit", "块");
    	set("long",
            "....水晶石....魔....并。\n");
    	set("value", 70);
    	set("material", "stone");
    	set("no_shown",1);
    	set("no_get",1);
    	set("no_drop",1);
/*    	set("skill", ([
            "name":         "fanwen",    
            "exp_required": 10000,      
			"sen_cost":		50,	
			"difficulty":	50,	
            "max_skill":    30      
		]) ); */
	}
    ::init_item();
}
