inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n"
"  \n"
"    漫天春雪来，才抵梅花半。最爱雪边人，楚些裁成乱。\n\n"
"    雪儿偏解饮，只要金杯满。谁道雪天寒？翠袖阑干暖。\n"
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
