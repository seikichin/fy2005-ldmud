#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 320
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "jeffz"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1568432238"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "明月阁");
set("long", "\n"
"水满青溪月满楼。客怀须赖酒消愁。\n"
"风回玉宇三更夜，露滴金茎八月秋。\n"
"情脉脉，思悠悠。星河织女隔牵牛。\n"
"乘槎欲把仙乡问，也似浮生有白。\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/sword8.c",
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
