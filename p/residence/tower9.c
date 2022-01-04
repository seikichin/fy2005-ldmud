

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "非天塔顶层");
  set ("long", "\n\n"
"　　　　　　　　长铗归来兮，食无鱼\n\n"
"　　　长铗归来兮，出无车\n\n"
"　　　　　长歌当哭兮，世无古龙。\n\n"
"");
        set("exits", ([
  "down" : __DIR__"tower8",
//  "up" : __DIR__"tower2", 
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
