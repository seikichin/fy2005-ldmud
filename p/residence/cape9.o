inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"    春花秋月何时了，往事知多少。\n"
"    小楼昨夜又东风，\n"
"    故国不堪回首月明中。\n\n"
"    雕栏玉砌应犹在，只是朱颜改。\n"
"    问君能有几多愁，\n"
"    恰似一江春水向东流。\n\n"
"\n"
"");
        set("exits", ([

  "down" : __DIR__"cape"+(query("floor")-1),
]));
        set("coor/x",-25);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
