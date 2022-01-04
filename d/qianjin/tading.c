inherit ROOM;
void create()
{
        set("short", "云雨舟大厅");
        set("long","红木舱板被擦的纹理并现。墙壁四周挂满了当地名人的书词提画。厅中一张大\n"
"红地毯，足有五丈方圆。几个纱衣朦胧的妙龄少女正在随歌而舞。有话：\n"
"[31m\n"
"                        绛衣披拂露盈盈，\n"
"                        淡染胭脂一朵轻。\n"
"[37m\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"boat3",
  "west" : __DIR__"wting",
  "east" : __DIR__"eting",
  "southup"   : __DIR__"stairs",
]));
       set("objects", ([
        __DIR__"npc/dancer" : 3,
                        ]) );

	set("coor/x",-65);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
