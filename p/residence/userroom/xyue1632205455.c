#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "xyue"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1632205455"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "月明居");
set("long", "\u620d\u9f13\u65ad\u4eba\u884c\uff0c\u8fb9\u79cb\u4e00\u96c1\u58f0\u3002;\u9732\u4ece\u4eca\u591c\u767d\uff0c\u6708\u662f\u6545\u4e61\u660e\u3002;\u6709\u5f1f\u7686\u5206\u6563\uff0c\u65e0\u5bb6\u95ee\u6b7b\u751f\u3002;\n\u5bc4\u4e66\u957f\u4e0d\u8fbe\uff0c\u51b5\u4e43\u672a\u4f11\u5175\u3002\n"
);
        set("exits", ([
"out" : "/p/residence/sword1.c",
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
