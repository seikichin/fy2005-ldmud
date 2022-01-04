

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"只要有爱，就有嫉妒。\n"
"也许有人说：“爱是奉献，不是佔有；既然是奉献，就不该嫉妒。”\n"
"说这句话的人若非圣贤，就是伪君子。\n"
"圣贤博爱。伪君子根本就不会对一个人真正爱过。\n\n"
"");
        set("exits", ([
  "down" : __DIR__"smile"+(query("floor")-1),
  "up" : __DIR__"smile"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
