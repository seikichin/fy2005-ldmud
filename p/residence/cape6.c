inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"    人生愁恨何能免？销魂独我情何限！\n"
"    故国梦重归，觉来双泪垂。\n\n"
"    高楼谁与上？长记秋晴望。\n"
"    往事已成空，还如一梦中。\n\n"
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
