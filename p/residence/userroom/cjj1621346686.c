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

#define OWNER "cjj"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1621346686"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "小昭寺");
set("long", "\u5927\u5a01\u5929\u9f99\u822c\u82e5\u8bf8\u4f5b\u822c\u82e5\u54aa\u561b\u54c4\u5927\u5a01\u5929\u9f99\u822c\u82e5\u8bf8\u4f5b\u822c\u82e5\u54aa\u561b\u54c4\u5927\u5a01\u5929\u9f99\u822c\u82e5\u8bf8\u4f5b\u822c\u82e5\u54aa\n\u561b\u54c4\u5927\u5a01\u5929\u9f99\u822c\u82e5\u8bf8\u4f5b\u822c\u82e5\u54aa\u561b\u54c4\u5927\u5a01\u5929\u9f99\u822c\u82e5\u8bf8\u4f5b\u822c\u82e5\u54aa\u561b\u54c4\u5927\u5a01\u5929\u9f99\u822c\u82e5\u8bf8\u4f5b\u822c\n\u82e5\u54aa\u561b\u54c4\n"
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
