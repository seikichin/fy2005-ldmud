inherit ROOM;
void create()
{
        set("short", "前花园");
        set("long","千金楼著名之处在这里可略见一斑，四边花草甚多，但唯有牡丹最胜。那花不\n"
"是寻常玉楼春之类，乃“姚黄”“魏紫”有名异品，一本价值五千。那花正种在朱\n"
"门对面，周围以湖石拦之。其花大如丹盘，五色灿烂，光华夺目。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"pingfeng",
  "southwest" : __DIR__"bamboo_bridge1",
  "north" : __DIR__"garden1",
  "south" : __DIR__"garden2",
]));
	set("outdoors","fengyun");
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
