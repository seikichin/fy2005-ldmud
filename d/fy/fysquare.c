#include <ansi.h>
#include <room.h>
inherit ROOM;

int count;

void create()
{
    set("short",HIR"风云天下"NOR);
    set("long","风风雨雨，风云城的中心广场依旧鲜亮如新。风道天街和云街地巷在这里交会，\n"
"四方立起了宏伟的风云天地四个祭坛，昔日的广场却并无多少变化，虽然中央的水\n"
"池已经干涸，虽然当年碧绿的池水和尾尾金鱼不复存在，留下的是个几丈方圆，深\n"
"不见底的大洞。水池旁的蟠龙摩天石柱饱经岁月沧桑，依然不屈不挠地耸立，石柱\n"
"上九条飞龙张牙舞爪，直欲冲天而去。往高处走一步，便是天下闻名的[1;31m天机阁[0;32m。\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"tiandoor",
	"south" : __DIR__"yundoor",
	"east" : __DIR__"didoor",
	"west" : __DIR__"fengdoor",
	"up":	__DIR__"fysquareu",

      ]));
    set("outdoors", "fengyun");
	set("tianji_square",1);
	

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",0);
    set("no_dazuo",1);
    set("no_study",1);
    
    count=0;
    set("time",time());
    setup();
    // To "load" the board, don't ever "clone" a bulletin board.
    call_other( "/obj/board/fysquare_b", "盘龙摩天柱");
}

void reset(){
	::reset();
	message("system", ""HIC"【闲聊】"NOR HIY"天机老人(Tian ji)"HIW": [1;31m风起云涌，天地变色，万物复苏，英雄辈出。[0;32m \n",users());
	set("time",time());
//	message("system", HIC"【闲聊】"NOR HIY"天机老人(Tian ji)"HIW ":" +sprintf("当前时间:%s \n",ctime(time())),users());
	count++;
}


int refresh(){
	int x;	
	x= 900+query("time")-time();
	if (count>1)
	     return x;
	else
		return 99999;
}

int valid_leave(object who, string dir) {
	if (dir == "up") {
		if (who->query("env/checkbrief") == 0) { 
			who->set("env/brief",1);
		}
	}
	return ::valid_leave(who,dir);
}