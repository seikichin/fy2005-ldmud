// sword_long.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(CYN"巫师长剑"NOR, ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "把");
    	set("long", "这是一把看起来相当普通的长剑，份量大约有十来斤左右。\n");
    	set("value", 300);
    	set("material", "steel");
    	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
    	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	::init_sword(100);
}
