#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "langxn"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1534189040"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "风云侠侣");
set("long", "\n"
"风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄 风云侠侣 绝代双骄\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/tower1.c",
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
