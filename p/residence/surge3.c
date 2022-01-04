inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n"
"  \n"
"    郁孤台下清江水，中间多少行人泪！ \n"
"    \n"
"    西北望长安，可怜无数山！ \n"
"    \n"
"    青山遮不住，毕竟东流去。 \n"
"    \n"
"    江晚正愁余，山深闻鹧鸪。\n"
"    \n"
"");
        set("exits", ([

  "down" : __DIR__"surge"+(query("floor")-1),
  "up" : __DIR__"surge"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
