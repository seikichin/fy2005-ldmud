
inherit ITEM;

void create()
{
	set_name("壁柜橱", ({"壁橱","壁柜","壁柜橱","closet"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown",1);
	set("prep","on");
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "个");
    	set("long", "一个壁柜橱，上面摆的是各种各样的酒。\n");
    	set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
