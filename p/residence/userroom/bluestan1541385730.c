#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "bluestan"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1541385730"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "康桥");
set("long", "\n"
"轻轻的我走了\n"
"正如我轻轻的来\n"
"我轻轻的招手\n"
"作别西天的云彩\n"
"那河畔的金柳\n"
"是夕阳中的新娘\n"
"波光里的艳影\n"
"在我的心头荡漾\n"
"软泥上的青荇\n"
"油油的在水底招摇\n"
"在康河的柔波里\n"
"我甘心做一条水草\n"
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
