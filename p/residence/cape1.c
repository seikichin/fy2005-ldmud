inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "天涯海角楼底层");
  set ("long", "\n\n"
"     别梦依依到谢家\n"
"     \n"
"     小廊回合曲阑斜\n\n"
"     多情只有春庭月\n"
"     \n"
"     犹为离人照落花\n"
"     \n"
"");
        set("exits", ([

  "northeast" : __DIR__"enterance",
   "up" : __DIR__"cape"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}
/*
*/