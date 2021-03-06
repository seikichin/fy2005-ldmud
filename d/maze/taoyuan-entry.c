// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "桃林");
	set("long","这本是一片茂密繁盛的桃花林，原本芳草鲜美，落英缤纷，虽时常笼罩着一层 \n"
"淡淡的薄雾，但也安谧祥和，然而近几月来，林中笼上了一层厚厚的桃花瘴，不仅\n"
"前路难辨，而且若是久呆其中，便会身中花毒。附近的老百姓们在树林入口竖起了 \n"
"一块石碑，鲜红如血的篆字告诉来往游客：[0;1;31m桃花瘴中无活人，勿入！[0m\n"
""
	);

	set("outdoors", "taoyuan");

	set("exits", ([ 
		"north" : AREA_TAOYUAN"taolin2",
		"south" : __DIR__"taoyuan-maze/entry",
	]));
	set("NONPC", 1);
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",-10);
	setup();

}

//	这儿演示 refresh maze,可以用flush来人工reset maze

void	init(){
	add_action("flush_maze","flush");
}


int	flush_maze(){
	object maze_room;
	string flush_msg;
	
	if (!wizardp(this_player()))
		return 0;
		
	maze_room=find_object(__DIR__"taoyuan-maze");
	if (!maze_room) return 1;
	flush_msg=MAG"\n忽然间一阵风吹过，周围的桃花枝忽然移动起来。。。。\n"
"一阵天摇地转，你发现自己又回到了桃花林的进口。\n\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

int	valid_leave(object who, string dir) {
	if (dir == "south")
	{
		if (!who->query_temp("maze/桃花林驱瘴散"))
		{
			message("vision",who->name()+"深深地吸了一口气，举步向林中走去，\n",this_object(),who);
			message("vision",MAG"一股淡淡的香雾从桃花林中飘散出来。。。。。。\n"NOR,this_object(),who);
			tell_object(who,MAG"你正欲踏入桃花林，突觉口鼻之中香味四散，胸中一阵绞痛，气血翻腾，\n"
"“扑通”一声，摔倒在地。\n"NOR);
			who->unconcious();
			return notify_fail ("");
		}
	}		
	return 1;
}