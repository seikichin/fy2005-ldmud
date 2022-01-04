inherit ROOM;
void create()
{
    set("short", "银钩赌坊大厅");
    set("long","一眼看过去，这大厅里真是金碧辉煌，堂皇富丽，连烛台都是纯银的，在这种\n"
"地方输了千儿八百两金子，没人会觉得冤枉。大厅里摆满了大大小小的赌桌，只要\n"
"能说出名堂的赌具，这里都有。有匾（ｓｉｇｎ）一块。\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"pianting",
	"north" : __DIR__"yingou",
      ]));
    set("item_desc", ([
	"sign": 
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;31m		小赌可安家，大赌可定邦[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"             \n"
"骰子的赌法：\n"

"ｂｅｔ　＜种类＞　＜银量＞\n"
"\n"
"种类：　０，１，２，３到１８\n"
"０：　		赌小	（３－１０）	一赔一\n"
"１：  		赌大	（１１－１８）	一赔一\n"
"２：　		赌围骰	（三粒骰子同点）一赔三十六\n"
"３－１８	赌单点  		一赔八\n"
"\n"
"例子：\n"
"ｂｅｔ　０　５０\n"
"赌五十两在小上\n"
"             \n"
"[0;1;37m────────────────────────────────[0m             \n"
""
      ]) );

    set("objects", ([
	__DIR__"npc/dice_thrower" : 1,
	BOOKS"skill/steal_30" : 1,
      ]) );
    set("NONPC",1);
    set("coor/x",-160);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fywest");
    setup();
}

void init(){
    object me;
    me = this_player();
    if( me->query("gamble/amount")) {
		tell_object(me, "你上次中途溜号，赌品太差了。\n");
		me->delete("gamble/amount");
		if (me->query_skill("betting",1))
		    me->decrease_skill("betting",1);
    }
}

void reset(){
    object obj;
    ::reset();
    if(!present("stealingbook", this_object())){
	obj = clone_object(__DIR__"npc/obj/stealingbook");
	if(objectp(obj)){
	    if(!obj->move(this_object()))
		destruct(obj);
	}
    }
}
