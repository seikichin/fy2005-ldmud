
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("月玉璧", ({ "yueyu" , "玉璧"}) );
	set_weight(50);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "块");
    	set("long", "这是一角玉璧，上面刻了个＂月＂字，\n"
"还刻了些奇怪的花纹，但只从这一角玉璧，你已经感到一种神奇的力量．\n"
"玉璧不时发出暗红色的光茫．\n");
    	set("value", 1);
	}
}



