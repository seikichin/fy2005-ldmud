inherit ROOM;
void create()
{
        set("short", "木拉提当铺");
        set("long","这个当铺是乌拉泊十里方圆唯一的一间当铺，生意不好也不坏，这里的主人是\n"
"本地人，人很好，从来就不想多占别人的便宜。当铺挂有牌（ｓｉｇｎ）一块。\n"
""
        );
        set("exits", ([ 
  "northwest" : __DIR__"bazha",
  "west" : __DIR__"bazha2",
  "southwest" : __DIR__"bazha3",
]));
        set("item_desc", ([
                "sign": "\n"
"这里是钱庄，目前我们提供的服务有：\n"
"\n"
"pawn        典当货物。\n"
"value       估价货物。\n"
"sell        卖断货物。\n"
"redeem      赎回货物。\n"
"\n"
""
        ]) );
        set("objects", ([
        __DIR__"npc/hockowner" : 1,
        __DIR__"npc/swaiter9" : 1,
        __DIR__"npc/swaiter10" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
