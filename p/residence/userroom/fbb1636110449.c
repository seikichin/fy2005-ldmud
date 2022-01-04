#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 40
#define R_FLAG 32
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "fbb"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1636110449"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "哪都通快递欢迎您");
set("long", "\u5c91\u592b\u5b50\uff0c\u4e39\u4e18\u751f\uff0c\u5c06\u8fdb\u9152\uff0c\u676f\u83ab\u505c\u3002\u4e0e\u541b\u6b4c\u4e00\u66f2\uff0c\u8bf7\u541b\u4e3a\u6211\u503e\u8033\u542c\u3002\u949f\u9f13\u9994\u7389\u4e0d\u8db3\u8d35\n\uff0c\u4f46\u613f\u957f\u9189\u4e0d\u590d\u9192\u3002\u53e4\u6765\u5723\u8d24\u7686\u5bc2\u5bde\uff0c\u60df\u6709\u996e\u8005\u7559\u5176\u540d\u3002\n"
);
        set("exits", ([
"out" : "/p/residence/smile1.c",
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
