// Room: /d/pk/turen5.c

inherit ROOM;
#include <ansi.h>
#include "turen_room.h"


void create()
{
	set("short", HIR "喋血场" NOR);
	set("long","这里阴森恐怖，地上到处是残肢碎尸，无处不是暗红色的血滴。你心中\n"
"忐忑不安，万分警惕，不知道从哪里就会窜出一个黑影。\n"
""
	);
	set("exits", ([
		"east"  : __DIR__"turen6",
		"south" : __DIR__"turen9",
		"west"  : __DIR__"turen4",
		"north" : __DIR__"turen2",
	]));
set("PK_FREE", 1);
set("no_death_penalty",1);
	setup();
       // replace_program(ROOM);
}