#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 240
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "fgb"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1533612622"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "朝廷居");
set("long", "\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"这是朝廷小号的房间\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/cloud6.c",
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
