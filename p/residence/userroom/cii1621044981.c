#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 160
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "cii"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1621044981"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "黄粱一梦居");
set("long", "\u9ec4\u7cb1\u4e00\u68a6\u53c8\u91cd\u6765\u5e7f\u9675\u6563\u7edd\u7434\u5f26\u65ad\u6d77\u5916\u661f\u6c89\u5251\u6c14\u9ec4\u7cb1\u4e00\u68a6\u53c8\u91cd\u6765\u5e7f\u9675\u6563\u7edd\u7434\u5f26\u65ad\u6d77\u5916\u661f\u6c89\u5251\u6c14\u9ec4\u7cb1\u4e00\u68a6\u53c8\u91cd\u6765\u5e7f\u9675\u6563\u7edd\u7434\u5f26\u65ad\u6d77\u5916\u661f\u6c89\u5251\u6c14\u9ec4\u7cb1\u4e00\u68a6\u53c8\u91cd\u6765\u5e7f\u9675\u6563\u7edd\u7434\u5f26\u65ad\u6d77\u5916\u661f\u6c89\u5251\u6c14\n"
);
        set("exits", ([
"out" : "/p/residence/smile4.c",
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
