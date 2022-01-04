// Room: dong1
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "山隙中");
        set("long","这里阴森黝暗，伸手不见五指，又极潮湿，仅容一人通过。向前方望去，却不\n"
"知有多深远。\n"
""
        );

       set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"dong0",
  "west" : __DIR__"gu",
 
]));
         
	set("coor/x",60);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
