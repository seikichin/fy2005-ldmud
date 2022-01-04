#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 240
#define R_FLAG 33
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "jademl"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1594968520"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "兰馨轩");
set("long", "\n"
"它枝叶茂密远看像大型盆景中的一棵劲松近看它的主干已经长到二尺多高了分出了数不清的枝权米兰叶子的形状跟公园种植的冬青差不多近似椭圆形中间还有一道不深不浅的小沟\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/smile6.c",
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