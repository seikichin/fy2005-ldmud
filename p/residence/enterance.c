#include <ansi.h>


inherit ROOM;
void create ()
{
  set ("short", CYN"【"WHT"枕霞之城"CYN"】"NOR);
  set("name","枕霞之城");
  set("id","Residence Area");
  set("channel_id","枕霞之城(Residence Area)");
  
  set ("long", "\n"
"爬上天梯，一阵阵微寒的风倾拂而过，抬眼是漫天的星光，月圆，四周都是萧\n"
"萧的雪。几条小路东南西北的延伸开来，通向远方略高的几块土地，然而小路下的\n"
"薄土只得三尺许厚，竟是悬空不落。不远处的雪地边缘插着面木牌[37m(Sign)[32m，你走去\n"
"扶着木牌垂望，只见百丈之下，依稀是风云城中闪烁的灯火。\n"
"");
        set("exits", ([ 
  "north" : __DIR__"smile1",
  "east" : __DIR__"tower1",
  "west" : __DIR__"sword1",
  "south" : __DIR__"cloud1",
//  "northeast" : __DIR__"moon1",
//  "northwest" : __DIR__"star1",
//  "southeast" : __DIR__"surge1",
//  "southwest" : __DIR__"cape1",
//  "down" : __DIR__"station",
  "down" : "/d/fy/station",

  "up" : __DIR__"annieshop",
]));
	set("item_desc", ([
			"sign": "\n"
"\n"
"　　　　　　　　　　╔——————————————————╗\n"
"　　　　　　　　　　┊　　　　　欢迎来到枕霞之城　　　　　│\n"
"　　　　　　　　　　┊　　　 　　　　　　　　　　　 　　　│\n"
"　　　　　　　　　　┊　　　 距风云天下一百四十四丈 　　　│\n"
"　　　　　　　　　　╚——————————————————╝\n"
"\n"
""
	]) );
  	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",10);
	set("NONPC",1);
	setup();
}


void process()
{
	BR_D->process();
	call_out("remove_x",43200*14);	// 12hr
}

void remove_x()
{
	set("ann",0);
}

void init()
{
	return ;
	if (!query("ann"))
	{
		set("ann",1);
        CHANNEL_D->do_channel( this_object(), "announce",sprintf(NOR YEL"風雲程式將在一分鐘後對住宅區進行檢索清理，期間可能有LAG情事，"NOR));
        CHANNEL_D->do_channel( this_object(), "announce",sprintf(NOR YEL"請盡快離開危險區域暫時等待，以護安全。"NOR));
		call_out("process",1);
	}
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
