inherit ROOM;

void create()
{
        set("short", "八角街");
        set("long","大昭寺外，围绕着寺院的八角街是布达拉宫里最繁华热闹的地方。所有最大的\n"
"客栈和商号都在这条街上。远处钟声不时的齐鸣。一声声梵唱随风飘来。宝塔的尖\n"
"顶在太阳下闪着金光，充满了神圣庄严肃穆的景象。\n"
""
        );
        
        set("exits", ([ 
		"north" : __DIR__"octo1",
		"west" : __DIR__"octo3",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama" : 1,
        ]) );
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}