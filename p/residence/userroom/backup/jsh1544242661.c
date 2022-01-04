#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 80
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "jsh"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1544242661"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "江山如画");
set("long", "\n"
"江山的房子，江山如画啊！\n"
"江山的房子，江山如画啊！\n"
"江山的房子，江山如画啊！\n"
"江山的房子，江山如画啊！\n"
"江山的房子，江山如画啊！\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/smile2.c",
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
