// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "争雄崖");
    set("long","竭尽浑身力气，终攀上这被称作东南第一峰的争雄崖，只三千里江河尽入\n"
"眼底，层层云气徊于身下，你仿如凌空而立，只有天在上，更无山与齐，心有\n"
"所感，慨然长叹：果真是邈仙山之峻极兮，闻天籁之嘈嘈，峰峥嵘以路绝，挂\n"
"星辰于岩嶅。\n"
""
NOR
        );
	set("objects", ([
		__DIR__"npc/xiaowu":1,
		__DIR__"npc/xiaofang":1,
//		__DIR__"npc/champion":1,
	]));
	set("item_desc", ([
	"cliff": "争雄崖下临万仞，山崖下云雾缥缈，若是不小心跌了下去，只怕会尸骨无存。\n",
	"山崖": "争雄崖下临万仞，山崖下云雾缥缈，若是不小心跌了下去，只怕会尸骨无存。\n",
	"崖": "争雄崖下临万仞，山崖下云雾缥缈，若是不小心跌了下去，只怕会尸骨无存。\n",

	]) );
	set("exits",([
  		"southdown" : __DIR__"peak8",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",100);
	set("coor/z",800);
	setup();
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


