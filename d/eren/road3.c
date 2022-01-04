inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山道");
        set("long","山路蜿蜒曲折，转了几个弯走进谷口，景色忽然一变，奇峰怪石，苍松青藤，\n"
"山色叠翠，重嶂千峰，直令人联想到中原的风光。昆仑山山势虽险绝，但这条路却\n"
"巧妙地穿过群山。那[37m恶人谷[32m便隐藏在正是群山围绕的谷底，若不是细心寻找，万万\n"
"发现不了。\n"
""
        );
        set("exits", ([ 
	"southup" : __DIR__"valleyentry",
	"northdown" : __DIR__"road4",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
