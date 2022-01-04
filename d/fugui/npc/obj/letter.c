inherit ITEM;

void create()
{
        set_name("推荐信", ({ "letter", "信"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "封");
                set("long", "一封推荐信，上边写着：\n"
"金大帅：此人英勇神武，当可完成你的运镖任务，请善待之。\n"
"        \n"
"此致                   \n"
"        敬礼\n"
"\n");
	}
        set("value", 0);
	::init_item();
}
