inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南宫钱庄");
        set("long","中原南宫世家，家财万贯，产业不可胜数。此间钱庄黑匾红字，正是南宫产业\n"
"之一。南宫钱庄的银票信誉极好，大江南北都可兑现。钱庄中央有一红木柜台，半\n"
"人多高，上有牌（ｓｉｇｎ）一块。\n"
""
        );
        set("item_desc", ([
                "sign": "\n"
"这里是钱庄，目前我们提供的服务有：\n"
"\n"
"convert     兑换钱币。\n"
"withdraw    提取存款。\n"
"deposit     存入钱币。\n"
"balance     察寻存款。\n"
"loan        向钱庄借钱。\n"
"transfer    直接转帐。\n"
"\n"
""
        ]) );


        set("objects", ([
                __DIR__"npc/bankowner" : 1,
        ]) );
        
        set("exits", ([ 
		"north" : __DIR__"vroad3",
	]));

	set("coor/x",70);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();

}
