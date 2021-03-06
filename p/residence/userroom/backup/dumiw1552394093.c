#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 320
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "dumiw"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1552394093"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "忘忧谷");
set("long", "\n"
"结庐在人境，而无车马喧。问君何能尔，心远地自偏。\n"
"    采菊东篱下，悠然见南山。山气日夕佳，飞鸟相与还。\n"
"    此中有真意，欲辨已忘言。此中有真意，欲辨已忘言。\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/tower8.c",
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
