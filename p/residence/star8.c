inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"    锦瑟年华谁与度\n"
"    \n"
"    莫问情归处  只影向斜阳\n"
"    \n"
"    剑吼西风  欲把春留驻\n"
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
