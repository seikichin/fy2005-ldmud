

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "非天塔"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"一个人的习惯，\n"
"往往是别人都知道，\n"
"而自己却是唯一不知道的人。\n\n"
"");
        set("exits", ([
"502" : __DIR__"userroom/shj1638368120",
"501" : __DIR__"userroom/haluo1512139252",
"down" : __DIR__"tower"+(query("floor")-1),
  "up" : __DIR__"tower"+(query("floor")+1), 
]));
  	set("coor/x",-10);
	set("coor/y",-40);
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
