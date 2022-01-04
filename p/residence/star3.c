inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"    魔坠凡尘 难遣流年老 \n\n"
"    人间道 天涯芳草 依旧情多好\n\n"
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
