inherit ROOM;
void create()
{
        set("short", "花海竹桥");
        set("long","竹桥上交缠蔷薇、木香、刺梅、金雀，桥下撒满凤仙、鸡冠、秋葵等种。更有\n"
"那金萱、百合、剪春罗、剪秋罗、满地娇、缠枝牡丹等类，不可枚举。遇开放之时，\n"
"烂漫如锦屏。远离数尺，尽植名花异草。一花未谢，一花又开。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"garden",
  "northwest" : __DIR__"bamboo_bridge2",
]));
        set("objects", ([
        __DIR__"npc/gongzi" : 1,
                        ]) );
	set("outdoors","fengyun");
	set("coor/x",-10);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
