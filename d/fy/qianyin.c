// inn.c

inherit ROOM;


void create()
{
    set("short", "千银当铺");
    set("long","此当铺是南风大街对面的千金楼所设。以方便手头不宽的嫖客。千金楼的姑娘\n"
"们也经常光顾这里，典当或是卖掉客人们高兴之余所赏赐的小玩意儿。此当铺虽然\n"
"是千金楼所属，但却童叟无欺。当铺挂有牌（ｓｉｇｎ）一块。\n"
);

    set("exits", ([
	"north"      : __DIR__"wcloud2",
	"west"      : __DIR__"qianyin_neitang",
      ]) );
    set("item_desc", ([
	"sign": "\n"
"这里是千银当铺，目前我们提供的服务有：\n"
"\n"
"pawn	    典当货物。\n"
"value       估价货物。\n"
"sell        卖断货物。\n"
"redeem      赎回货物。\n"
"\n"
""
      ]) );


    set("objects", ([
	__DIR__"npc/hockowner" : 1,

      ]) );


    set("coor/x",-120);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
}
