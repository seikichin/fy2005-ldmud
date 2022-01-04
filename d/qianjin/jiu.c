inherit ROOM;
void create()
{
        set("short", "湖上酒");
        set("long","湖上酒，终日助清欢。\n"
"檀板轻声银甲缓，醅浮香米玉蛆寒，醉眼暗相看。\n"
"春殿晚，仙艳奉杯盘。\n"
"湖上风光真可爱，醉乡天地就中宽，帝王正清安。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hua",
  "northeast" : __DIR__"shui",
]));
        set("objects", ([
        __DIR__"npc/jiu" : 1,
                        ]) );

	set("coor/x",-45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
