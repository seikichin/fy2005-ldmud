inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山村道尽头");
        set("long","再往前就快出村了，青石路至此而止。引人注目的是路旁的草地上有一座二人\n"
"高的铁像，塑一大手大脚的虬髯汉子，两条发墨般的浓眉，棱棱的颧骨，一只瘦骨\n"
"嶙峋的大手抓着柄已锈得快烂的铁剑。\n"
""
        );
        set("exits", ([ 
	"west" : __DIR__"vroad4",
	"northwest" : __DIR__"groad5",
	"southeast":  __DIR__"waterfall",
	"east": __DIR__"orchard1",
	]));
        set("objects", ([
        	__DIR__"obj/statue":1,
	]) );
	set("outdoors", "eren");
        set("coor/x",100);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
}
