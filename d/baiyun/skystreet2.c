//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "天街");
    set("long","走进城门，一条长街笔直向前，隐没于亭殿之中。天街的两旁由连檐通脊的长廊\n"
"甚是整齐工直。你心中径自生出一股严肃庄穆的气氛来，禁不住的收敛了笑意。\n"
);
    set("exits",
      ([
	"north" : __DIR__"3xian",
	"west" : __DIR__"gallery",
	"east" : __DIR__"musicshop",
	"south" : __DIR__"fightdoor",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
