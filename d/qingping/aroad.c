inherit ROOM;
void create()
{
        set("short", "青石小路");
        set("long","这是一条青石小路，两边种满了花卉，还有些药材，显得非常的幽静，向前是\n"
"长长的青石路，小路一端的尽头似乎有一道小圆门，路两侧是几间房子，正是清平\n"
"弟子的卧室所在，八大弟子分住南北两间。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road2",
  "west" : __DIR__"ting",
   ]));

   	set("outdoors","qingping");
	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
