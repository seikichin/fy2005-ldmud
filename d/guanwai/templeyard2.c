
inherit ROOM;

void create()
{
        set("short", "寺院");
        set("long","壮丽的寺院，光线却十分阴森幽暗。数千只巨烛和用牛油作燃料的青铜灯在风\n"
"中闪动着神秘的火焰。高耸的寺墙上有无数的神龛，供奉着面目狰狞的巨人七色像，\n"
"在闪动的烛光中，更显得鬼秘可怖。\n"
""
        );
        set("exits", ([ 
  			"north" : __DIR__"tower",
		]));
        set("outdoors", "guanwai");
	        set("objects", ([
        __DIR__"npc/yellama" : 1,
        ]) );
	
    	set("coor/x",0);
    	set("coor/y",-10);
    	set("coor/z",0);
    	setup();
        replace_program(ROOM);

}

