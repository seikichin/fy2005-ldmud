
inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long","这里黑黑暗暗，几乎伸手不见五指。唯一的光亮来自墙上忽明忽暗的松油灯。\n"
"地上和墙上布满了暗红色的血痕，散发出阵阵腥气。不断传来的哀嚎声在死沉的地\n"
"牢里回荡，令人毛骨耸然。\n"
""
        );
        set("exits", ([ /* sizeof() == 3 */
//  "north" : __DIR__"tunnel1",
  "west" : __DIR__"tunnel6",
  "east" : __DIR__"tortureroom",
]));

	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",5);
	setup();
        replace_program(ROOM);

}

