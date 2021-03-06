#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long","穿过松树林，一条小路出现在眼前，石阶铺就的山路断断续续先前延伸。路旁\n"
"石壁上生长着一大片青苔，触手之下冰凉湿润，青苔下石缝间有水滴一滴滴缓缓流\n"
"下，最后凝聚在一个小小的石凹里。\n"
""
        );
    set("exits", ([ 
  		"northeast" : __DIR__"ziqi",
	    "westup" : __DIR__"yanluo",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-35);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
}

void init() {
//	object me;
	add_action("do_search", "search");
}

int do_search() {
	object me, ob;
	
	me = this_player();
	
	message("vision", me->name() + "在草丛中仔细寻找。\n", environment(me), me);
	
	if (me->query("marks/turtle_room")==base_name(this_object())
			&& me->query_temp("marks/search_turtle")!=2) {
		if (me->query_temp("marks/search_turtle")==1) {	
			tell_object(me, "你拨开草丛仔细寻找，竟然发现一只背壳上生满细细绿毛乌龟在慢慢爬。\n"); 
			me->set_temp("marks/search_turtle",2);
			ob = clone_object(AREA_HUANGSHAN"npc/turtle");
			if(objectp(ob)) {
				ob->set("turtle_owner",me);
				if (!ob->move(this_object()))
				{
					destruct(ob);
					tell_object(me,"绿毛乌龟向你怀里钻了钻，没找到地方就爬开了。\n");
				}
			}
			return 1;
		}
	
		if (!present("green turtle", this_object())) {
			tell_object(me, YEL"花草丛中似乎有什么慢慢动了一下，你以为自己眼花了。\n"NOR); 
			me->set_temp("marks/search_turtle", 1);
			return 1;
		} 
	}
	
	tell_object(me,"你在花草中找来找去，什么也没有发现。\n");
	return 1;
}