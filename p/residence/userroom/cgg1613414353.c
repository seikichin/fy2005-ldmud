#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "cgg"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1613414354"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "武当通天");
set("long", "\n"
"武当通天道人的家为的是省钱啊也不知道是不是亏本的买卖可是没有自己的房子还是不好搞啊什么先天无上罡气不就是修仙术嘛武当能不能成为乌龟流的高手呢试试看吧\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/smile9.c",
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	set("timestamp",TIMESTAMP);
	set("timestamp2",TIMESTAMP2);
	set("free_space",FREE_SPACE);
	set("basic_tax",BASIC_TAX);
	set("basic_score_tax",BASIC_SCORE_TAX);
	set("tree",CONSTRUCT_TREE);
	set("total_gold",TOTAL_GOLD);
	set("total_score",TOTAL_SCORE);
	setup();

}
