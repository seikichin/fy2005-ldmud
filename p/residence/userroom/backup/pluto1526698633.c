#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 120
#define R_FLAG 33
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "pluto"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1526698633"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "狐狸窝");
set("long", "\n"
"平凡，自开天以来，上苍就赐予了我们这个权利，可是，我们却疏忽它，不要它。平凡，自开天以来，上苍就赐予了我们这个权利，可是，我们却疏忽它，不要它。平凡，自开天以来，上苍就赐予了我们这个权利，可是，我们却疏忽它，不要它。平凡，自开天以来，上苍就赐予了我们这个权利，可是，我们却疏忽它，不要它。\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/smile3.c",
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
