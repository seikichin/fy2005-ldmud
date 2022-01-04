#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 40
#define R_FLAG 33
#define FREE_SPACE 2
#define CONSTRUCT_TREE 1
#define BASIC_TAX -1
#define BASIC_SCORE_TAX 200

#define TOTAL_GOLD 300
#define TOTAL_SCORE 240

#define OWNER "suki"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1512782020"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "豹豹乐园");
set("long", "\n"
"这里是豹豹的游乐园，里面有很多的玩具，跷跷板，木马，秋千，一应俱全，每到休息的时候，豹豹会和小朋友们来这里愉快的玩耍。\n"
"这里是豹豹的游乐园，里面有很多的玩具，跷跷板，木马，秋千，一应俱全，每到休息的时候，豹豹会和小朋友们来这里愉快的玩耍。\n"
"这里是豹豹的游乐园，里面有很多的玩具，跷跷板，木马，秋千，一应俱全，每到休息的时候，豹豹会和小朋友们来这里愉快的玩耍。\n"
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