inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("书架", ({ "书架" , "shelf"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "个");
    	set("long", "一个打扫得干干净净的书架。\n");
    	set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


