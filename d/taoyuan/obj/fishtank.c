inherit ITEM;
inherit F_LIQUID;

void create()
{
   	set_name("小鱼缸", ({ "fish tank" , "fishtank", "yugang"}) );
   	set_weight(300);
   	set_max_encumbrance(200);
   	if( clonep() )
    	set_default_object(__FILE__);
   	else {
    	set("prep", "in");
      	set("unit", "个");
      	set("long", "鱼缸不大却十分精致，白色的瓷面上均匀地布满细碎的裂纹，\n"
"上面绘有荷花的图案。 \n");
      	set("value", 100);
       	set("marks/haswater", 0);
   }
    ::init_item();
}

int is_container() { return 1; }

void init() {
	add_action("do_fill", "fill");
}

int do_fill(string arg)
{
    string name, type, container;
    
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
    	return notify_fail("你上一个动作还没有完成。\n");
    if( !environment(this_player())->query("resource/water") )
    	return notify_fail("这里没有地方可以装水。\n");
	if(query("marks/haswater")) {
		tell_object(this_player(),"鱼缸里已经装满水了呀！\n");
		return 1;
	} else {
		message_vision("$N蹲下身，将" + name() + "里装满了水。\n", this_player());
    	set("marks/haswater", 1);
    	set("long", "小鱼缸里装了大半缸水，荷花的图案在水波的映衬下显得栩栩如生。\n");
    	set_weight(1000);
	}
    return 1;
}
