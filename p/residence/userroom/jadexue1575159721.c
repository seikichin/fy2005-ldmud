#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 240
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "jadexue"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1575159721"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "无情室");
set("long", "\n"
"别墅共有三层，由于是依山而建的，所以每一层的景色都各有千秋。进入大门，\n"
"是一条用鹅卵石铺成的小路，小路的两旁是一排石凳，石凳上排列着形态各异的花木盆景，\n"
"让人赏心悦目。\n"
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
