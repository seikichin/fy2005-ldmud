

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "登天殿"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", "\n\n"
"剑是优雅的，是属于贵族的，刀却是普遍化的，平民化的。\n"
"有关剑的联想，往往是大宫廷裡，在深山裡，在白云间。\n"
"刀却是和人类的生活息息相关的。\n"
"奇怪的是，在人们的心目中，刀远比剑更残酷更惨烈更凶悍更野蛮更刚勇。　\n\n"
"");
        set("exits", ([

  "down" : __DIR__"cloud"+(query("floor")-1),
  "up" : __DIR__"cloud"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-50);
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
