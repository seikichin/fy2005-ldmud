// inn.c

inherit ROOM;


void create()
{
    set("short", "南宫钱庄");
    set("long","中原南宫世家，家财万贯，产业不可胜数。此间钱庄黑匾红字，正是南宫产业之\n"
"一。南宫钱庄的银票信誉极好，大江南北都可兑现。就是富可敌国的金钱帮，也难望\n"
"其项背。钱庄中央有一红木柜台，半人多高，上有牌（ｓｉｇｎ）一块。\n"
"[31m\n"
"                	南宫钱庄\n"
"[37m\n"
);

    set("exits", ([
	"south"      : __DIR__"wcloud2",
      ]) );
    set("item_desc", ([
	"sign": "\n"
"这里是钱庄，目前我们提供的服务有：\n"
"\n"
"convert     兑换钱币\n"
"withdraw    提取存款\n"
"deposit     存入钱币\n"
"balance     查询存款数额\n"
"loan	    向钱庄借钱\n"
"transfer    直接转帐\n"
"\n"
""
      ]) );


    set("objects", ([
	__DIR__"npc/bankowner" : 1,

      ]) );

    set("coor/x",-120);
    set("coor/y",20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}
