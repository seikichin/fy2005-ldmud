inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"    天涯芳草无归路  回首花无数  \n\n"
"    解语自销魂  \n\n"
"    弱袂萦春  尘缘不相误 \n\n"
"");
        set("exits", ([

  "down" : __DIR__"star"+(query("floor")-1),
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
