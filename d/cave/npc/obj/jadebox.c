inherit ITEM;
void create()
{
    set_name("雀翎玉盒", ({ "jadebox", "box", "jade box" }) );
	set_weight(500);        
	set_max_encumbrance(800);	
	set("prep","on");        
    	set("unit", "个");
       	set("long", "一个制作巧夺天工的白玉盒子。\n");
    	set("prep", "里");
    	set("value", 100);
    	set("closed", 1);
	::init_item();
}

int is_container() 
{ 
	return 1; 
}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}
int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "jadebox" )
                return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	message_vision("$N小心翼翼打开$n。\n", me, ob);
	ob->set("closed",0);
        return 1;
}

int is_closed()
{
	return (({int}) this_object()->query("closed"));
}
