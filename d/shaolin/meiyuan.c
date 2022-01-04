// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "梅园");
        set("long","半亩见方的园子，种满了梅树。园中梅枝横斜交错，疏密有致。这里清净整洁，\n"
"似乎经常有人来打扫。 \n"
""
        );
        set("exits", ([ 
 	 "east" : __DIR__"banruo",
  	"west" : __DIR__"shan",
	]));
    
       set("objects", ([
//               __DIR__"obj/meizhi" : 1,
       ]) );
       
    set("outdoors", "shaolin");
	set("coor/x",-5);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}

/*
void init()
{
	object me,meizhi;
	if (!random(50))
	{
		if(interactive(me = this_player()) && !me->is_fighting() && userp(me))
		{
			if (!present("meizhi",this_object()))
			{
				meizhi = clone_object(__DIR__"obj/meizhi");
				meizhi->move(this_object());
			}
		}
	}
}

*/