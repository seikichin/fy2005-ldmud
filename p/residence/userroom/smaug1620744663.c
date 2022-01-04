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

#define OWNER "smaug"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1620744663"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "日靖四方");
set("long", "我将我享，维羊维牛，维天其右之。仪式刑文王之典，日靖四方。\n伊嘏文王，既右飨之。我其夙夜，畏天之威，于时保之。\n"
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
