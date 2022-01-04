#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 240
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "cjb"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1620746387"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "测试房间");
set("long", "\u4e16\u4e0a\u6709\u4e9b\u4e8b\u6b63\u662f\u5982\u6b64\uff0c\u8d8a\u60f3\u5f97\u591a\uff0c\u987e\u8651\u8d8a\u591a.\u4e16\u4e0a\u6709\u4e9b\u4e8b\u6b63\u662f\u5982\u6b64\uff0c\u8d8a\u60f3\u5f97\u591a\uff0c\u987e\u8651\u8d8a\u591a,\u82e5\u662f\u4e0d\u60f3\u5c31\u505a\uff0c\u53cd\u800c\u8bf4\u4e0d\u5b9a\u80fd\u505a\u5f97\u901a\u3002\u82e5\u662f\u4e0d\u60f3\u5c31\u505a\uff0c\u53cd\u800c\u8bf4\u4e0d\u5b9a\u80fd\u505a\u5f97\u901a\u3002\n"
);
        set("exits", ([
"out" : "/p/residence/tower6.c",
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
