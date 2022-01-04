inherit ROOM;
void create()
{
        set("short", "南天门");
        set("long","这是到达天街所必经的南天门，门前一座摩天阁，巍峨庄重，气势不凡，门上\n"
"石刻，极尽巧力，鬼斧神工，四根红木大柱，虽饱经风雨，却颜色不改，临风远眺，\n"
"不由让人想起“天门一长啸，万里清风来”。由此向上，便到了泰山的后山，后石\n"
"邬，东面是泰山山神碧霞元君接收人间供奉之所在，西面便是玩赏明月的观月峰。\n"
""
        );
        set("exits", ([ 
  "down" : __DIR__"shiba",
  "west" : __DIR__"shanfeng",
  "north" : __DIR__"houshi",
  "east" : __DIR__"bixia",
]));

        set("item_desc", ([
                "石刻": "		\n"
"		阶		门\n"
"		崇		辟\n"
"		万		九\n"
"		级		霄\n"
"		俯		仰\n"
"		临		步\n"
"		千		三\n"
"		嶂		天\n"
"		奇		胜\n"
"		观		迹\n"
"		 。		 ，			\n"
""        ]) );
        set("objects", ([
        __DIR__"npc/pettrainer" : 1,
                        ]) );
        set("outdoors", "taishan");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}
