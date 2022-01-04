#define X_COOR -30
#define Y_COOR -40
#define Z_COOR 360
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "oer"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1633401737"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "欧尔");
set("long", "\u4eba\u7c7b\u6700\u5927\u7684\u75db\u82e6\u4e5f\u8bb8\u5c31\u662f\u6c38\u8fdc\u65e0\u6cd5\u63a7\u5236\u81ea\u5df1\u7684\u601d\u60f3\u4eba\u7c7b\u6700\u5927\u7684\u75db\u82e6\u4e5f\u8bb8\u5c31\u662f\u6c38\u8fdc\u65e0\u6cd5\n\u63a7\u5236\u81ea\u5df1\u7684\u601d\u60f3\u4eba\u7c7b\u6700\u5927\u7684\u75db\u82e6\u4e5f\u8bb8\u5c31\u662f\u6c38\u8fdc\u65e0\u6cd5\u63a7\u5236\u81ea\u5df1\u7684\u601d\u60f3\u4eba\u7c7b\u6700\u5927\u7684\u75db\u82e6\u4e5f\n\u8bb8\u5c31\u662f\u6c38\u8fdc\u65e0\u6cd5\u63a7\u5236\u81ea\u5df1\u7684\u601d\u60f3\u4eba\u7c7b\u6700\u5927\u7684\u75db\u82e6\u4e5f\u8bb8\u5c31\u662f\u6c38\u8fdc\u65e0\u6cd5\u63a7\u5236\u81ea\u5df1\u7684\u601d\u60f3\u4eba\n\u7c7b\u6700\u5927\u7684\u75db\u82e6\u4e5f\u8bb8\u5c31\u662f\u6c38\u8fdc\u65e0\u6cd5\u63a7\u5236\u81ea\u5df1\u7684\u601d\u60f3\n"
);
        set("exits", ([
"out" : "/p/residence/sword9.c",
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
