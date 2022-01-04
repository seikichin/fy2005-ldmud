#define X_COOR -20
#define Y_COOR -50
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "azure"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1617663492"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "青青河边树");
set("long", "\n"
"渐吹尽枝头香絮是处人家绿深门户远浦萦回暮帆零乱向何许阅人多矣谁得似长亭树树若有情时不会得青青如此日暮望高城不见只见乱山无数韦郎去也怎忘得玉环分付第一是早早归来怕红萼无人为主算空有并刀难剪离愁千缕\n"
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
