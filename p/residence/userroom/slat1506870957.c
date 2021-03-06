#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 17
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "slat"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1506870957"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "懒人居");
set("long", "\n"
"山不在高，有仙则名。水不在深，有龙则灵。\n"
"斯是陋室，惟吾德馨。苔痕上阶绿，草色入帘青。\n"
"谈笑有鸿儒，往来无白丁。\n"
"可以调素琴，阅金经。无丝竹之乱耳，无案牍之劳形。\n"
"南阳诸葛庐，西蜀子云亭。\n"
"孔子云：何陋之有？\n"
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
