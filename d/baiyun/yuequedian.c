//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "月阙殿");
    set("long","再行不远，一座雄伟壮丽的大殿呈现在眼前。金瓦琉璃，在宽阔的庭院下和高大\n"
"的建筑物前，所谓天高地广，人自然更渺小。竟然生出一种“唯我独尊”的天子气氛\n"
"来。\n"
);
    set("exits", 
      ([
	"north" : __DIR__"fightdoor",
	"south" : __DIR__"jietiandian",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-220);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
