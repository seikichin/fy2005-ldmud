#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "yyh"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1558400131"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "美人居");
set("long", "\n"
"长安回望绣城堆山顶千门次第开一骑红尘妃子关无人知是荔枝来长安回望绣城堆山顶千门次第开一骑红尘妃子关无人知是荔枝来长安回望绣城堆山顶千门次第开一骑红尘妃子关无人知是荔枝来长安回望绣城堆山顶千门次第开一骑红尘妃子关无人知是荔枝来\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/cloud1.c",
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
