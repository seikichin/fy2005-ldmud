inherit ITEM;

void create()
{
        set_name("羊皮纸", ({"parchment", "paper"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",funcall(#'read_file,__DIR__"parchment"));
                set("value", 1);
        }
}
