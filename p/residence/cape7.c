inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n"
"  \n"
"    深院静，小庭空，\n\n"
"    断续寒砧断续风。\n\n"
"    无奈夜长人不寐，\n"
"    \n"
"    数声和月到帘栊。\n\n"
"\n\n"
"");
        set("exits", ([

  "down" : __DIR__"cape"+(query("floor")-1),
  "up" : __DIR__"cape"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
