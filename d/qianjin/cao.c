inherit ROOM;
void create()
{
        set("short", "湖上草");
        set("long","湖上草，碧翠浪通津。\n"
"修带不为歌舞缓，浓铺堪作醉人茵，无意衬香衾。\n"
"晴霁后，颜色一般新。\n"
"游子不归生满地，佳人远意正青春，留咏卒难伸。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lastbridge",
  "southeast" : __DIR__"hua",
]));
        set("objects", ([
        __DIR__"npc/cao" : 1,
                        ]) );

	set("coor/x",-55);
	set("coor/y",5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
