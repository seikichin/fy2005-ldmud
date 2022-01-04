inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "坟场西侧");
        set("long","阴惨惨的夜色，笼罩着阴惨惨的大地，这儿孤零零地有座十米见方的坟冢，四\n"
"周有石人石马，显然主人是附近的富绅。但是现在石人石马已经缺头断腿，坟头上\n"
"长满了荒草，见人走近，几只乌鸦呱呱地一哄而散。坟旁有棵枯树。\n"
""
        );
        set("outdoors", "biancheng");
        set("coor/x",-110);
    	set("coor/y",10);
    	set("coor/z",0);
    	set("no_lu_letter",1);
	
    	set("objects", ([
               	__DIR__"obj/tree":	1,
         ]) );		
    	set("exits", ([
			"east" : __DIR__"cemetery10",
		]));
    	set("bird_out",1);
    	setup();
}

void init(){
	int i;
	object me;
	me = this_player();
	if (query("bird_out")) call_out("do_bird", 4, me);
}

int do_bird(object ob) {

	if(!ob || !userp(ob) || environment(ob) != this_object()){
		return 1;
	}	
	if (!REWARD_D->riddle_check(ob,"喋血鹦鹉") && !REWARD_D->check_m_success(ob,"喋血鹦鹉"))
	{
		tell_object(ob, HIR"\n"
"忽然间，一样东西从坟堆间飞了起来——是一只鸟，一只脖子上挂着铃的鸟。铃\n"
"声怪异而奇特，就仿佛要摄人的魂魄。转瞬间，鸟飞远了，铃声也远了。\n"NOR);
		REWARD_D->riddle_set(ob,"喋血鹦鹉",1);
	}
	return 1;	
}


void reset()
{
	object item, coffin;
	object *inv, *players;
	
	::reset();
	set("bird_out",1);
	if (!objectp(coffin=present("tree",this_object()))) return;
	inv=all_inventory(this_object());
	players=filter(inv,(: userp($1) :));
	if (sizeof(players)) return;
	
	if (!present("ribbon",coffin)) {
		item=clone_object(__DIR__"obj/ribbon");
		item->move(coffin);
	}
	return;
} 

