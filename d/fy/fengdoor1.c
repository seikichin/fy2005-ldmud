#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"风坛"NOR);
        set("long","		\n"
"      	       .\n"
"              /=\\		\n"
"             /===\ \	            风坛乃金钱帮所建，坛中流光溢彩，金碧\n"
"            /=[0;1;37m风[0m==\' \	   	辉煌，供奉的风神暗中道出上官意欲呼风唤雨\n"
"           /=======\'' \	权倾朝野的野心。即使在风云城如此龙虎汇聚、\n"
"          /=========\ '  \	奇人辈出的地方，上官金虹依旧可以说得上官\n"
"         /====[0;1;37m坛[0m=====\' /	金虹依旧可以说得上是武林中的霸主，江湖中\n"
"        /=============\/	的皇帝。\n"
"                   \n");
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wcloud1",
  "east" : __DIR__"fysquare",
  "north" : __DIR__"qcyzdian",
  "south" : __DIR__"pxhdian",
]));
        set("outdoors", "fengyun");
        set("objects", ([
//        __DIR__"npc/mei": 1,
                        ]) );

	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
//	replace_program(ROOM);
}


/*
void init() {
	  add_action("do_dazuo","dazuo");
	}
	
int do_dazuo(string arg) {
	object me;
	me=this_player();
	tell_object(me,"此地不能打坐。\n");
	return 1;
}*/

