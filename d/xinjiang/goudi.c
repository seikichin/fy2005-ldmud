/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "沟底");
        set("long","沟底两边长满了老树，即使是盛夏天气，这里的温度也相当低，一阵阵凉风吹\n"
"来，暑气全消，时间长了，还会感到寒冷。除了一两声若隐若现的鸟叫之外，四周\n"
"真是静，出奇的静，令人毛骨悚然，冷汗凛凛的静。\n"
""
        );
        set("exits", ([ 
  "west" : __DIR__"baiyang",
  "east" :  __DIR__"goudi2",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
