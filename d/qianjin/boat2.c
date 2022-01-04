inherit ROOM;
void create()
{
        set("short", "云雨舟甲板");
        set("long","湖色淡绿，天色淡蓝。微波荡漾，风景宜人。一声声划拳行酒令，加杂着女人\n"
"的娇笑，不时的从船舱中传出。聆耳细听，风声中似乎还加杂着低低的悲泣之声。\n"
"与船上的欢声笑语极不融洽。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"boat1",
  "west" : __DIR__"boat3",
]));
        set("objects", ([
        __DIR__"npc/shuishou" : 2,
	__DIR__"npc/mother": 2,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
