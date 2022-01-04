inherit ROOM;
void create()
{
        set("short", "地下室");
        set("long","黑咕隆咚\n"
""
        );
/*        set("exits", ([ 
  "southwest" : __DIR__"hehuadang2",
]));
*/
	set("indoors","qianjin");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",-20);
	
	set("objects", ([
		__DIR__"npc/meihuadao" : 1,
	]));   	
	setup();

}

void init()
{
//        if(!wizardp(this_player()))
//	{
//	"/cmds/std/look"->look_room(this_player(),this_object());
//	this_player()->set("startroom", __FILE__);
        add_action("do_nothing", "");
        add_action("do_look","look");
        add_action("do_chat","chat");        
        add_action("do_emote","chat*");                
	add_action("do_quit","quit");
//	}
}	

int do_nothing(string arg)
{
	if (this_player()->query_temp("marks/meihuadao") 
	) {
		write("你心下大急，百般挣扎，无奈穴道被点，一动也不能动．．．．！\n");
		return 1;
	}
	else return 0;
}

int do_chat(string arg)
{
	CHANNEL_D->do_channel(this_player(), "chat", arg);
	return 1;
}

int do_emote(string arg)
{
	//EMOTE_D->do_emote(this_player(), "chat", arg);
    CHANNEL_D->do_channel(this_player(), "chat*", arg);
	return 1;
}
int do_look(string arg)
{
    "/cmds/std/look"->main(this_player(),arg);
    return 1;
}

int do_quit()
{
	"/cmds/usr/quit"->main(this_player(),"");
	return 1;
}
