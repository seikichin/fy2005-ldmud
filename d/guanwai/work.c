// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "石场");
        set("long","恰克卜里山盛产各种上等石料。这里硝烟弥漫，很多人都在辛苦的劳动着。用\n"
"自己的汗水去换取一些收入。每个到这里工作的人都可以拿到一份很公平的报酬。\n"
"许多人正在忙忙碌碌的工作着，门口挂著一块牌子[37m(sign)[32m。\n"
""
        );

    set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"stoneroad",
		"north" : __DIR__"octo5",
		"south" : __DIR__"birdroad",
	]));
        set("outdoors", "guanwai");

        set("item_desc", ([
                "sign": "\n"
"现在正紧缺人手，急需雇佣一批短工来干活。\n"
"\n"
"work     开始工作。\n"
"\n"
""
		
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_work", "work");
}

void	reset() {
    	set("worked",0);
		::reset();
}

int do_work(string arg)
{
        object ob;
        object me;

		if (query("worked")> 20)
			return notify_fail("这批石头搬完了，等下批吧。\n");
			
        me = this_player();
		if(me->is_busy()) return notify_fail("你的动作还没有完成，不能工作。\n");
		message_vision("$N辛苦的工作终于结束了，可人也累的要死。\n", me);
		add("worked",1);
		me->receive_wound("gin",30,me);
		me->receive_wound("sen",30, me);
//		me->status_msg("all");
		me->set_temp("last_damage_from","在恰克卜里山局石场干活劳累过度而死。\n");
		ob = clone_object("/obj/money/silver");
		if (!ob->move(me))
			ob->move(environment(me));
		message_vision("老板对$N说：这是你的工钱。\n", me);
		me->perform_busy(2);
		return 1;
}
