#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 320
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "cll"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1621341520"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "青霜小筑");
set("long", "\u96c4\u5173\u6f2b\u9053\u771f\u5982\u94c1\u800c\u4eca\u8fc8\u6b65\u4ece\u5934\u8d8a\u76ee\u524d\u98ce\u4e91\u6bcf\u4e2a\u4eba\u53ea\u80fd\u9020\u4e00\u95f4\u623f\u76ee\u524d\u98ce\u4e91\u6bcf\u4e2a\u4eba\u53ea\u80fd\u9020\n\u4e00\u95f4\u623f\u96c4\u5173\u6f2b\u9053\u771f\u5982\u94c1\u800c\u4eca\u8fc8\u6b65\u4ece\u5934\u8d8a\u76ee\u524d\u98ce\u4e91\u6bcf\u4e2a\u4eba\u53ea\u80fd\u9020\u4e00\u95f4\u623f\u76ee\u524d\u98ce\u4e91\u6bcf\u4e2a\u4eba\n\u53ea\u80fd\u9020\u4e00\u95f4\u623f\n"
);
        set("exits", ([
"out" : "/p/residence/smile8.c",
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
