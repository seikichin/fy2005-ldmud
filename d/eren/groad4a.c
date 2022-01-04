inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "竹林");
        set("long","竹林茂密，你脚下的柔软细草恰可没足，耳边有啾啾鸟语，鼻中又嗅着花草幽\n"
"香，透过林间，隐约可见北方农家的炊烟，远远的好象有十余只猴儿在林间跳跃相\n"
"戏，一片太平景象。竹林南边，依稀有条小路。\n"
""
        );
        set("exits", ([ 
	"north" : __DIR__"groad4",
	"south" : __DIR__"groad5",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",90);
        set("coor/y",80);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
