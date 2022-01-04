// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "甬路");
        set("long","边走边看碑文，不知不觉已经走到了碑林尽头，前面便是三大殿之第一处所在--\n"
"天王殿，甬路到此开始顺阶而上，过了石陛便到天王殿。\n"
""
        );
        set("exits", ([ 
  "south" : __DIR__"yingbi",
  "north" : __DIR__"tianwang",
  "northeast" : __DIR__"yeeast",
  "northwest" : __DIR__"yewest",
]));
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
