// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "艳洞");
        set("long","刚才好似天堂，现在你却似身在地狱，四周是昏黄发红的光线，你不由觉得\n"
"好热，而且越来越热，似乎有火在煎熬着你，走了几步四周景色没有改变，耳边\n"
"不时传来少女低声的呻吟，和着周围火热的岩石，你不禁越来越烦燥。\n"
""
        );
   set("exits", ([ 
      "south": __DIR__"migong.c",
      "north": __DIR__"migong2.c",
   ]));
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
