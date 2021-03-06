#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 80
#define R_FLAG 32
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "sunn"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1506956576"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "大平层");
set("long", "\n"
"屋里没有装修，白色的墙，黑色的窗。家具只有一张床和一个黑色的巨大箱子，丝毫看不出有人住的痕迹。唯有大箱子上硕大的锁表明里面装满了主人珍贵的收藏。\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/sword2.c",
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
