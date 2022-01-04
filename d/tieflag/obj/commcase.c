#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("箱子", ({ "woodcase" , "case"}) );
        set_weight(500);
        set_max_encumbrance(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",
		"这是一个普普通通的箱子。你可用它（make）或（remake）兵器。\n");
	}
    ::init_item();
}
int is_container() { return 1; }
void init()
{
	add_action("do_make","make");
}

int do_make(string arg)
{
	object me;
	object obj;
	me=this_player();
        if(environment()==this_player() && ({int}) this_player()->query("sen")>250)
{		
	if(!arg) return 0;
	{
	me->set("sen",0);
		if(arg=="axe")        {obj=clone_object(__DIR__"cmaxe");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把斧。\n");}
        	if(arg=="blade")      {obj=clone_object(__DIR__"cmblade");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把刀。\n");}     	
		if(arg=="dagger")     {obj=clone_object(__DIR__"cmdagger");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把匕首。\n");}
        	if(arg=="fork")       {obj=clone_object(__DIR__"cmfork");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把叉。\n");}
        	if(arg=="hammer")     {obj=clone_object(__DIR__"cmhammer");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把锤。\n");}
        	if(arg=="staff")      {obj=clone_object(__DIR__"cmstaff");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把杖。\n");}   
	     	if(arg=="sword")      {obj=clone_object(__DIR__"cmsword");obj->move(me);  
write("你将手中的箱子打开，用其中的零件拼成了一把剑。\n");}
        	if(arg=="whip")       {obj=clone_object(__DIR__"cmwhip");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把鞭。\n");}		
		destruct(this_object());
	}
	return 1;
}
	return 0;
}          
