
inherit ITEM;

void create()
{
	set_name("陶罐", ({"陶罐", "pot" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "个");
    	set("long", "一个经年历久，早已褪去色泽的陶罐。\n");
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
