// Tie@fy3
inherit ROOM;
void create()
{
	set("short", "会客室");
	set("long","这里是管理人员会客和聊天讨论的地方。\n"
""
	);
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",20);
	set("no_magic",1);
	setup();
	call_other("/obj/board/query_b", "???");
}


void init()
{
	object room;
	if(!wizardp(this_player()) && userp(this_object()))
	{
		if(!room = find_object(AREA_FY"church"))
		room = load_object(AREA_FY"church");
		this_player()->move(room);
	}
}