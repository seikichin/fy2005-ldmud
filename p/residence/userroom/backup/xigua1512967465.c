#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 120
#define R_FLAG 1
#define FREE_SPACE 3
#define CONSTRUCT_TREE 1
#define BASIC_TAX 560
#define BASIC_SCORE_TAX 300

#define TOTAL_GOLD 600
#define TOTAL_SCORE 380

#define OWNER "xigua"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1512967465"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "侠客行");
set("long", "\n"
"对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。对不起，描述必需是中文。\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/sword3.c",
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
