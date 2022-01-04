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

#define OWNER "cnn"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1621347170"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "雷府");
set("long", "\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\n\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\u96f7\u52a8\u4e8e\u4e5d\u5929\u4e4b\u4e0a\n"
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
