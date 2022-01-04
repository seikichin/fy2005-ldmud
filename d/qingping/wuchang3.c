inherit ROOM;
void create()
{
        set("short", "武场");
        set("long","武场的南端与北端遥遥相对，清平门下弟子多在北面练轻功及下盘，在这里练\n"
"各式各样的兵刃，当然用的最多的还是剑。武场靠墙处的槐树阴下是一个放置兵器\n"
"的架子，平日有弟子练武时，上面摆满了十八般兵刃，但现在却显得空空荡荡。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wuchang1",
]));

   	set("outdoors","qingping");
	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
