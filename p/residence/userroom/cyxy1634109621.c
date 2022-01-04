#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 240
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "cyxy"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1634109621"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "春云夏雨");
set("long", "\u6625\u4e91\u590f\u96e8\u79cb\u6708\u591c,\u5510\u8bd7\u664b\u5b57\u6c49\u6587\u7ae0\u3002\u597d\u96e8\u77e5\u65f6\u8282\uff0c\u5f53\u6625\u4e43\u53d1\u751f\u3002\u968f\u98ce\u6f5c\u5165\u591c\uff0c\u6da6\u7269\u7ec6\u65e0\n\u58f0\u3002\u91ce\u5f84\u4e91\u4ff1\u9ed1\uff0c\u6c5f\u8239\u706b\u72ec\u660e\u3002\u6653\u770b\u7ea2\u6e7f\u5904\uff0c\u82b1\u91cd\u9526\u5b98\u57ce\u3002\u6625\u591c\u559c\u96e8\u5510\u4ee3\uff1a\u675c\u752b\n"
);
        set("exits", ([
"out" : "/p/residence/smile6.c",
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
