inherit ROOM;
#include <ansi.h>

void create ()
{
  	set ("short", HIC"风云台"NOR);
  	set ("long", "\n"
"迷惘之中，你来到这片莫名的大陆，幽长古老的石台四壁上似乎刻满了一些生\n"
"疏歪斜的文字：甲戌年三月初三，小李寻欢惜别爱侣诗音，远赴京城应试，题记于\n"
"此。。；辛未年腊月十三，顽童留香，铁花，冰燕在此结拜金兰，同闯江湖！，庚\n"
"午年七月初七，萧石逸自此隐名萧十一郎，大盗萧十一郎！。。而在不起眼的墙壁\n"
"一隅，刻着一行金字：	[41;1m风云暨出，谁与争锋[2;37;0m\n"
"			\n");

 	set("no_magic",1);
	set("no_fight",1);
  	set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"newbie2",
  		
	]));
  
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",950);
  	
  	setup();
  
}
int valid_leave(object me, string dir){
     me->set("env/show_way",1);
	return ::valid_leave(me, dir);
}
