#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 360
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX 280
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "cmm"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1618046130"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "长胜居");
set("long", "\n"
"长胜八百战武艺天下尊孙长胜名字叫长胜但是武功就差那么一些些意思了不过只要找那些武功造诣不如他的人也可保长胜不败所以长胜居这个名字也是保得住的必经没交手就不会败的道理还是很好用的\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/smile9.c",
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
