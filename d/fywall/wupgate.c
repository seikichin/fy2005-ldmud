inherit ROOM;
void create()
{
    set("short", "西城门楼");
    set("long","门楼呈方形，往下望是川流不息的人群，阳光下，流动的人群象微风中的彩带,\n"
"东方是风云城的中心，就是在这里也可以依稀的看到风云广场中心的纹龙柱。城中\n"
"的房屋连绵不断，索碎的小路象细小的银蛇，蜿蜒盘旋在灰色的房屋之间.\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"down" : AREA_FY"wgate",
	"north" : __DIR__"wwall1",
	"south" : __DIR__"wwall10",
      ]));

    set("objects", ([
	__DIR__"npc/a" : 1,
      ]) );



    set("outdoors", "fengyun");
    set("coor/x",-300);
    set("coor/y",0);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
