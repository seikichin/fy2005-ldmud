#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 320
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "caa"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1621338435"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "白府");
set("long", "\u5f53\u5e74\u5927\u5929\u90aa\u65bc\u5170\u5929\u864e\u4e3a\u4f7f\u6625\u98ce\u5feb\u610f\u5200\u6cd5\u66f4\u4e0a\u5c42\u697c\u66fe\u4ee5\u5341\u6570\u8f7d\u65f6\u95f4\u6e38\u5386\u795e\u5dde\u4e00\u65e5\u95f4\u8ff7\u9014\n\u4e8e\u5927\u6f20\u701a\u6d77\u5343\u91cc\u9e23\u6c99\u5374\u65e0\u610f\u95f4\u8e0f\u5165\u4e86\u9ec4\u6c99\u4e2d\u4ece\u4e0d\u672a\u4eba\u6240\u77e5\u7684\u5343\u91cc\u843d\u96c1\u8349\u573a\u66f4\u56e0\u6b64\u673a\u7f18\n\u627e\u5230\u4e86\u4ed6\u82e6\u82e6\u8ffd\u5bfb\u7684\u6625\u98ce\u5feb\u610f\u4e4b\u9053\n"
);
        set("exits", ([
"out" : "/p/residence/smile8.c",
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
