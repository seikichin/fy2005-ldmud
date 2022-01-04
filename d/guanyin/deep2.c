// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "石峰深处");
        set("long","这些石峰，半由天生，半由人力，其中道路盘旋，竟隐含生克变化之理，正如\n"
"诸葛武侯的八阵图一般，除了尽人力之极致外，还加以天道之威，当真是鬼斧神功，\n"
"人所难测。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road4",
  "north" : __DIR__"narrow",
]));

        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
