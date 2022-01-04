#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "myu"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1503291004"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "辋川");
set("long", "\n"
"\n"
"　　积雨空林烟火迟，\n"
"　　蒸藜炊黍饷东菑。\n"
"　　漠漠水田飞白鹭，\n"
"　　阴阴夏木啭黄鹂。\n"
"　　山中习静观朝槿，\n"
"　　松下清斋折露葵。\n"
"　　野老与人争席罢，\n"
"　　海鸥何事更相疑。 \n"
"\n"
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
