#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIM"玲珑冠"NOR, ({ "coronal"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 40);
		set("armor_prop/armor", 8);
		set("armor_prop/strength", 4);
		set("armor_prop/intelligence", 20);
		set("armor_prop/composure", 4);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 4);
		set("armor_prop/karma", 4);
		set("armor_prop/max_gin", 400);
		set("armor_prop/max_kee", 170);
		set("armor_prop/max_sen", 400);
//		set("long","描述\n");	// 已废弃
set("value", 550000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_head();
}

// 凝輕·dancing_faery@hotmail.com

