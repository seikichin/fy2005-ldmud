inherit ROOM;
void create()
{
        set("short", "湖上花");
        set("long","湖上花，天水浸灵芽。\n"
"浅蕊水边匀玉粉，浓苞天外剪明霞，日在列仙家。\n"
"开烂熳，插鬓若相遮。\n"
"水殿春寒幽冷艳，玉轩晴照暖添华，清赏思何赊。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cao",
  "east" : __DIR__"jiu",
]));
        set("objects", ([
        __DIR__"npc/hua" : 1,
                        ]) );

	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
