#include <ansi.h>
inherit __DIR__"quicksand.c";

void create()
{
	object san, sna;
	set("short", "大漠风沙");
	set("long","你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼的风\n"
"声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间仿佛只剩下\n"
"你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。\n"
""
	);
	set("exits", ([ 
  "west" : __DIR__"desert6",
  "north" : AREA_GUANYIN"entrance",
  "south" : __DIR__"desert1",
  "east"  : __DIR__"desert8",
  "down"  : __DIR__"quicksand2",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"obj/hu-blade" : 1,
                 __DIR__"obj/skeleton" : 1,
                "/obj/money/silver": 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1080);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        san = present("sand", this_object());
        sna = present("hu-blade", this_object());
        sna->move(san);
        sna = present("skeleton", this_object());
        sna->move(san);
        sna = present("silver", this_object());
        sna->move(san);

}

