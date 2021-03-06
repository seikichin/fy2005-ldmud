
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "洞穴");
        set("long","借著手中的光亮，你看清楚了四周的景色。只见怪石林立，道路错综复杂，你\n"
"已经迷失了方向。几只小老鼠在你脚边跑来跑去。在这里，你根本分不清东南西北；\n"
"而东南西北对你来说，也没有任何意义。是生是死，只能听天由命。。\n"
""
        );
        set("exits", ([ 
		"east" : __DIR__"lighthole1",
		"west" : __DIR__"lighthole2",
		"north" : __DIR__"holeopen2",
		"south" : __DIR__"lighthole4",
	]));
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	int	kar;
	object	box, pearl;

	if(!arg && !this_player()->query_temp("marks/boxp")) {
		kar = this_player()->query("kar");
		if(random(kar+70) < kar) {
			message_vision(BLU "\n在黑暗中$N四处摸索，突然$N触到了一个突出的石壁上，\n上面似乎有个盒子。\n"NOR, this_player());
	    	seteuid( geteuid(this_player()));
			box = clone_object(__DIR__"obj/box");
			pearl = clone_object(__DIR__"obj/pearl");
			pearl->move(box);
			box->move(this_object());
			this_player()->set_temp("marks/boxp", 1);
			return 1;
		}
	}
        return notify_fail("\n你在黑暗中四处摸索，却甚麽都没发现。\n");
}

