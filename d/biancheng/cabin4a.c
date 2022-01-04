inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "厨房");
        set("long","西面的厨房是一间刷白了的屋子。椽子上吊着几只熏火腿，窗台上摆着盆花，\n"
"钉上挂着刀具，还有少见的大杯子、瓷器和躐制器皿，还有灶神的几幅画像。一张\n"
"狭长的粗木桌子上摆好了许多碗和匙，放着两个刚煎好的荷包蛋，还有新鲜的豆腐、\n"
"莴笋和用盐水煮的花生。\n"
""
        );
        set("exits", ([ 
	"north": __DIR__"cabin4",
	]));
        set("objects", ([
        	__DIR__"npc/taipo":	1,
	]) );
	set("coor/x",-60);
        set("coor/y",-45);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
