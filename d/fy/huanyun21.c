#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",CYN"环云道"NOR);
    set("long","环云道以南云街为中轴，贯穿整个风云南城，东侧是江湖人常去的客栈铁铺祭\n"
"剑亭等，西侧则是灯红酒绿的烟花之地，热闹非凡。虽然来来往往的好多都是初闯\n"
"江湖的男男女女，谁敢说不会有将来的将相王侯，高僧奇侠。西部有一个大水池，\n"
"水色墨绿，散发着淡淡的青烟。烟色迷离，一切都笼罩在似乎不存在的烟中。\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun3",
	"southeast" : __DIR__"huanyun22",
	"west" : __DIR__"hfeng",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",-60);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

