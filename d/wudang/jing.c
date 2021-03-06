
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "水井中");
    set("long","在水井中睁眼四望，四周井壁滑不留手。你心里后悔不及，不知如何才能出去。\n"
"井中灰朦朦的，象是什么都没有。如果四周搜索一下，也许有所发现。\n"
""
	);
    set("item_desc", ([
        "wall": "滑不留手的井壁。你可以试着爬(climb)上去。\n",
        "井壁": "滑不留手的井壁。你可以试着爬(climb)上去。\n",
	]) );
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",-90);
	set("underwater",120);
	set("water_damage",20);
	setup();
}

void init()
{
   	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
		add_action("do_climb", "climb");
    	add_action("do_search", "search");
}


int do_search(string arg)
{
    object ob;
    
    ob = this_player();
    if( ob->is_busy() )
        return notify_fail("你的动作还没有完成，不能移动。\n");
    message_vision("$N仔细的查看四周的井壁，搜遍了各个角落。\n", ob);
    ob->start_busy(2);
    call_out("search_obj", 4, ob);
    return 1;
}

int search_obj(object me)
{
    int kar;
    int exp;
    object sword, box ;
    
    if(!(this_object()->query("marks/没了")))
    {
        kar = ({int})me->query_kar();
        if( kar > 40 ) kar = 40;
		
        if( (random(40 - kar) < 5)  
        	&& (REWARD_D->riddle_check(me,"古井疑云") == 4 
        		|| REWARD_D->riddle_check(me,"古井疑云") == 5
        		|| REWARD_D->riddle_check(me,"古井疑云") == 6
        		|| REWARD_D->riddle_check(me,"古井疑云") == 7
        		))	// realistically, killing guo or not shouldn't affect search result.
        {
            this_object()->set("marks/没了", 1);
            message_vision(HIY "$N找到了一个长方铁盒，放进了怀里。\n"NOR, me);
            me->set_temp("marks/七星剑", 1);
            me->ccommand("remove all");
            seteuid(geteuid(me));
            sword = clone_object(__DIR__"obj/msword2");
            box = clone_object(__DIR__"obj/box");
            sword->set_temp("marks/owner", me);
            sword->set_temp("marks/owner_name",me->query("id"));
            sword->move(box);
            box->move(me);
			REWARD_D->riddle_set(me,"古井疑云",7);
        }
        else message_vision("$N什么都没找到。\n", me);
    }
    else message_vision("$N什么都没找到。\n", me);
    return 1;
}

int do_climb(string arg)
{
    object obj, me;
    int	kar;
    
    if(!arg || arg=="") return notify_fail("你要往哪里爬？\n");
    me = this_player();
    if( arg == "wall" || arg == "井壁" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision("$N使出吃奶的力量，顺着井壁向上爬去。\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("你不可以爬"+arg+"！\n");
}       

int climb_wall(object me)
{
    int kar;
    if (me->is_ghost()) return 0;
    kar = ({int})me->query_kar();
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->set_temp("marks/井时", 0);
        me->move(__DIR__"wudang3.c");
        message_vision("$N从水中湿淋淋的爬了出来。\n", me);
    }
    else message_vision("$N手上一个没抓稳，又掉了下来。\n", me);
    return 1;
}


void reset()
{
    ::reset();
    delete("marks/没了");
}
