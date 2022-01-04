inherit ROOM;
void create()
{
        set("short", "大巴札");
        set("long","巴扎就是集市的意思，乌拉泊的“巴扎”早在多年前就是“丝绸之路”上最有\n"
"名的地方。每逢赶“巴扎”时，各种土特产品，手工艺品，瓜果蔬菜等一起向“巴\n"
"扎”涌来。随时随地都可以看到头戴花帽，赶着小毛驴车，身着盛装的人。\n"
""
        );
        set("exits", ([ 
  "north" : __DIR__"beimen",
  "southeast" : __DIR__"bazha1",
  "southwest" : __DIR__"bazha2",
]));
        set("objects", ([
        __DIR__"npc/swaiter4" : 1,
        __DIR__"npc/swaiter5" : 1,
	__DIR__"npc/swaiter6" : 1,
	__DIR__"npc/swaiter11" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
