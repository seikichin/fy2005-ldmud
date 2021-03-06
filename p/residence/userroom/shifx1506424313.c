#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "shifx"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1506424313"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "藏剑阁");
set("long", "\n"
"\n"
"\n"
"\n"
"　　　　少年听雨歌楼上，红烛昏罗帐。\n"
"\n"
"　　　　壮年听雨客舟中，江阔云低，断雁叫西风。\n"
"　　　　而今听雨僧庐下，鬓已星星也。\n"
"\n"
"　　　　悲欢离合总无情，一任阶前点滴到天明。\n"
"\n"
"\n"
"\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/sword1.c",
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
