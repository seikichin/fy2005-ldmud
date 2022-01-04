#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "暗黑风云入口");
        set("long", "准备房间\n"
        );
        set("exits", ([ /* sizeof() == 4 */
  			"up" : "/d/fy/fysquare",
  			"down":	"/d/wiz/demoroom",
		]));
        set("objects", ([
        ]) );

        set("coor/x",-40);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
}

void init()
{
}

