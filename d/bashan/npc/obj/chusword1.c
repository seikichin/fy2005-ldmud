// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(YEL"古剑·莫邪"NOR, ({ "ancient sword","sword" }) );
	set_weight(4000);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "柄");
    	set("long", "一柄样式奇古的短剑，黄色的剑柄上雕刻着繁复的花纹。\n看起来不甚起眼的短剑里，容合了中华文明千年的侠行正气。\n");
    	set("material", "bronze");
    	set("no_get",1);
    	set("nodrop_weapon",1);
	}
	::init_sword(120);	
}

void init()
{
	set("weapon_wielded","握");
}
