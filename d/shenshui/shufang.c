// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long","一张红木书桌放在正中，墙角书架之上，遍藏诸子百家与武学典籍，墙壁都已\n"
"被书画挂满。书桌上有一个古色古香的小鼎，里面不知道燃烧着什么东西，整个书\n"
"房被一层淡紫色的烟雾笼罩着。\n"
""
        );
        set("exits", ([ 
  "west" : __DIR__"huayuan",
]));
   set("objects", ([
      __DIR__"npc/swordmaster": 1,
   ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
