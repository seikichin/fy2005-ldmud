#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"五"HIB"彩"HIG"海"HIY"螺"NOR,({ "conch shell","conch","shell" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		    	set("value",2000);
                set("material", "wood");
                set("long", "一个流光四溢，五彩斑斓的海螺，你可以吹吹看。\n");
                set("desc_ext", "blow conch shell");
        }
	::init_item();
}

void init()
{
        if (environment()== this_player())
        	add_action("do_blow", "blow");
}

int do_blow(string arg)
{
        object ob;
        
        
        if (!arg)	return 0;
        ob = present(arg, this_player());
        if (!ob || ob!= this_object())	return 0;
        	
        if ( this_player()->query("force") < 50 )
        {
        	message_vision("$N内力不足，不能吹"+ this_object()->name() + "。\n" , this_player() );
        	return 1;
        }
        else if ( this_player()->query("force_factor") < 40 )
        {
        	message_vision("$N鼓起腮帮子，粗着脖子吹起"+ this_object()->name() + "，但什么声响也没有。\n" , this_player() );
        	tell_object(this_player(),"最少需要40点加力（enforce 40）\n");
        	return 1;
        }
        else
        {
        	message_vision("$N轻轻吹了下" + this_object()->name() + "，顿时“嘟嘟”作响。。\n", this_player() );
        	message_vision("$N试著记住了" + this_object()->name() + "所发出的音律，便把" + this_object()->name() + "随手丢掉。\n", this_player() );
			this_player()->set_temp("annie/wolf_conch",1);
			destruct(this_object());
        	return 1;
        }	
}


