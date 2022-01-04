inherit ITEM;

void create()
{
        set_name("纸条", ({"paper", "纸"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张沾满血的纸，借着月光，你隐约可以看到：\n"
"	\n"
"	你若不是王动，就是替死鬼。\n"
"	\n"
"\n");
                set("value", 0);
        }
	::init_item();
}
