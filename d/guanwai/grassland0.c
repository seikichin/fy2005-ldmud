inherit ROOM;

void create()
{
        set("short", "草原");
        set("long","这里是一望无际的大草原。绿色的草地美丽得就象晴朗的蓝天。草原上三三两\n"
"两的羊群则是蓝天上飘浮的朵朵白云。远处的布达拉宫在骄阳下看来亮如纯银；到\n"
"了夕阳西下时又变得灿烂如黄金。你也许从没想到，在塞外的边陲之地竟有如此美\n"
"妙的地方，美得辉煌而神秘，美得令人迷惑，美得令人都醉了。\n");

        set("exits", ([ 
		"east" : "/d/quicksand/mroad2",
		"west" : __DIR__"grassland1",
	]));
        set("objects", ([
                __DIR__"npc/skylark" : 1,
        ]) );
        set("outdoors", "guanwai");
	set("coor/x",90);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
