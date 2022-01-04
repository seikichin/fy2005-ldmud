inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"    临流揽镜曳双魂  落红逐青裙  \n\n"
"    依稀往梦幻如真  泪湿千里云\n"
"    \n"
"");
        set("exits", ([

  "down" : __DIR__"star"+(query("floor")-1),
  "up" : __DIR__"star"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
