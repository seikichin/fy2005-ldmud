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

#define OWNER "ooo"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1632300305"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "皓月宫分号");
set("long", "\u6de1\u6de1\u7684\u6a80\u6728\u9999\u5145\u65a5\u5728\u8eab\u65c1\uff0c\u9542\u7a7a\u7684\u96d5\u82b1\u7a97\u6855\u4e2d\u5c04\u5165\u6591\u6591\u70b9\u70b9\u7ec6\u788e\u7684\u9633\u5149\uff0c\u7cbe\u81f4\u7684\u96d5\u82b1\n\u88c5\u9970\u7684\u662f\u4e0d\u51e1\uff0c\u53e4\u7434\u7acb\u5728\u89d2\u843d\uff0c\u94dc\u955c\u7f6e\u5728\u6728\u5236\u7684\u68b3\u5986\u53f0\u4e0a\uff0c\u6ee1\u5c4b\u5b50\u90fd\u662f\u90a3\u4e48\u6e05\u65b0\u95f2\u9002\n\u3002\n"
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
