// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "洞口");
        set("long","走出山洞，你的眼前豁然开朗。泉水叮咚，百鸟欢唱。时不时有少女的笑声传\n"
"了过来。两边奇峰怪石，前面一大片翠绿的草地，开放着许多不知名的花草。香气\n"
"传来，令人心情舒畅，你感到走入了世外桃源一般。\n"
""
        );

       set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gu0",
  "east" : __DIR__"dong1",
 
])); 

	set("outdoors","tieflag"); 		
         
	set("coor/x",50);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}

