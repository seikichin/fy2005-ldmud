// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER2;

void create()
{
	set_inherit_room(__DIR__"maze2-room");

	set_maze_long(5,5,4);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("down");

	set_link_entry_dir("down");
	set_link_entry_room(__DIR__"couplemaze_3");
	set_link_entry_room_x(-40);
	set_link_entry_room_y(-40);
	set_link_entry_room_z(10);
	
	set_link_exit_dir("up");
	set_link_exit_room(__DIR__"churoom_1");

	set_entry_short(CYN"巴山古迹"NOR);
	set_entry_desc("\n"
"穿过石屋迷阵，已然身处于半山之上。回头望去，只见巴山终年潮湿多雨的天\n"
"气在山地上风蚀出无数坑坑洼洼的小洞，倚山而建的黑石屋密密匝匝，过去就是古\n"
"佛窑，再望远看，便是劫余岭终年不散的迷雾。繁茂的树丛阻挡在你眼前，身侧的\n"
"一株参天大树上隐有人攀爬过的痕迹。\n"
""
);

	set_exit_short(CYN"粗大枝干"NOR);
	set_exit_desc("\n"
"行走在参天巨木的粗大枝干之上，你不由感叹於造化之奇，竟能有这样密密一\n"
"片树林，为巴山深处的隐秘提供了一道人力难以桓越的天然屏障。枝干前方挂着几\n"
"根儿臂粗细的藤条，看起来甚是结实，或许能让你继续前进。\n"
""
);

	set_maze_room_short(MAG"巴山古迹"NOR);
	set_maze_room_desc("\n"
"穿过石屋迷阵，已然身处于半山之上。回头望去，只见巴山终年潮湿多雨的天\n"
"气在山地上风蚀出无数坑坑洼洼的小洞，倚山而建的黑石屋密密匝匝，过去就是古\n"
"佛窑，再望远看，便是劫余岭终年不散的迷雾。繁茂的树丛阻挡在你眼前，身侧的\n"
"一株参天大树上隐有人攀爬过的痕迹。\n"
""
);

	set_outdoors(1);

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
