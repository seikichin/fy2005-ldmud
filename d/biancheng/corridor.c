inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "走廊");
        set("long","偏厅向东是一条不长的走廊，通向客人歇息的房间。自白天羽二十年前遇刺身\n"
"亡后，神刀门在江湖上的地位渐渐被万马堂所取代，堂主马空群论武艺，论交际，\n"
"都是响当当的角色，所以慕名来访的，有事相求的络绎不绝，万马堂的客房永远是\n"
"满满的。\n"
""
        );
        set("exits", ([ 
	"west": __DIR__"pianting",
	"east": __DIR__"corridor2",
	"north": __DIR__"room3",
	]));
        set("objects", ([
	]) );
        set("coor/x",0);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
