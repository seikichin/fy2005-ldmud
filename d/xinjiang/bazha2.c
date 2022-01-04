inherit ROOM;
void create()
{
	set("short", "南宫钱庄");
	set("long","中原南宫世家，家财万贯，产业不可胜数。此间钱庄黑匾红字，正是南宫产业\n"
"之一。南宫钱庄的银票信誉极好，大江南北都可兑现。就是富可敌国的金钱帮，也\n"
"难望其项背。钱庄中央有一红木柜台，半人多高，上有牌（ｓｉｇｎ）一块。\n"
"[31m\n"
"                	南宫钱庄\n"
"[37m\n"
""
	);
	
	set("exits", ([
		"west"    	: __DIR__"swind5",
	]) );
        set("item_desc", ([
                "sign": "\n"
"这里是钱庄，目前我们提供的服务有：\n"
"\n"
"convert     兑换钱币。\n"
"withdraw    提取存款。\n"
"deposit     存入钱币。\n"
"balance     察寻存款。\n"
"loan	    向钱庄借钱。\n"
""
        ]) );

        set("exits", ([ 
  "northeast" : __DIR__"bazha",
  "east" : __DIR__"bazha1",
  "southeast" : __DIR__"bazha3"
]));
        set("objects", ([
        __DIR__"npc/bankowner" : 1,
        __DIR__"npc/swaiter7" : 1,
        __DIR__"npc/swaiter8" : 1,
                        ]) );
        //set("no_pk",1);
        
        
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
