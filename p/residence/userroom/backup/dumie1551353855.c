#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 320
#define R_FLAG 1
#define FREE_SPACE 1
#define CONSTRUCT_TREE 1
#define BASIC_TAX 140
#define BASIC_SCORE_TAX 100

#define TOTAL_GOLD 150
#define TOTAL_SCORE 120

#define OWNER "dumie"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1551353855"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "狂风居");
set("long", "\n"
"东临碣石，以观沧海。水何澹澹，山岛竦峙。\n"
"    树木丛生，百草丰茂。秋风萧瑟，洪波涌起。\n"
"    日月之行，若出其中；星汉灿烂，若出其里。幸甚至哉，歌以咏志。\n"
"\n"
""
);
        set("exits", ([
"out" : "/p/residence/tower8.c",
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
