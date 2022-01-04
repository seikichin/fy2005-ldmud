// maple_leaf

#include <weapon.h>
#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIR"枫叶"NOR, ({ "maple leaf", "leaf" }) );
	if( clonep() )
    	set_default_object(__FILE__);
	else {
	set("no_split",1);
    	set("long",	"一片绚丽的枫叶。上面有几行娟秀的楷书。\n\n"
"　　霜明月起， \n"
"　　人在天涯远。 \n"
"　　此夜秋长别时短。 \n"
"　　但一般红叶， \n"
"　　飘落溪头芳草岸， \n"
"　　梦里歌轻笑浅。\n"
"\n"
"　　算青青郁郁， \n"
"　　那惯经寒？ \n"
"　　总把相思付红染。 \n"
"　　星河淡，金风散漫， \n"
"　　欲相诉无从遣双鱼。 \n"
"　　且寄与清波， \n"
"　　潺潺流遍。 \n"
"\n");
    	set("unit", "片");
    	set("weight",1);
	}
	set("castable",1);
	::init_item();
}
