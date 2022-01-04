#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 80
#define R_FLAG 33
#define FREE_SPACE 3
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 300

#define TOTAL_GOLD 600
#define TOTAL_SCORE 380

#define OWNER "liz"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1510132206"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "漩涡");
set("long", "\n"
"漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡漩涡\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/tower2.c",
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
