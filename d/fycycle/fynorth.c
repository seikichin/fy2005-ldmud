inherit ROOM;
void create()
{
        set("short", "风云城北");
        set("long","这是风云城北的一个市集。南北大道横穿市集。北穿白山黑水，直达松花江。\n"
"南接风云京都，再通江南海口。干线上商旅不绝，一条车痕向南方和北方伸展。东\n"
"西方向是一条小路，向东通向山区，向西通向大漠。\n"
""
        );
        set("exits", ([ 
	"east" : __DIR__"road4",
  "west"  : __DIR__"road3",
  "north" : "/d/laowu/road0",
  "south" : "/d/fy/ngate",
]));
        set("outdoors", "laowu");
	set("coor/x",0);
	set("coor/y",320);
	set("coor/z",0);
        replace_program(ROOM);
        setup();
}

