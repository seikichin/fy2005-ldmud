inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "小木屋");
        set("long","屋子虽然简陋，布置得却很舒服，很干净，炕上的被褥是刚换的。旁边放着一\n"
"只铁火盆，炖着奶茶，还带着羊膻气味呢：火星子偶尔一亮，照亮了墙上的套马杆\n"
"子、一大堆牛骨头，旁边摆着佛爷龛。\n"
""
        );
        set("exits", ([ 
	"east" : __DIR__"smallroad4",
	"south": __DIR__"cabin4a",
	]));
        set("objects", ([
	]) );
	set("coor/x",-60);
        set("coor/y",-40);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
