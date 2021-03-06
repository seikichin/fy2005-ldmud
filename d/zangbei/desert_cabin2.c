inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "残旧的屋子");
        set("long","残旧的屋子里，几乎什麽都没有，却供着个很大的神龛，神龛里有尊佛像，使\n"
"得这屋子看来更是诡秘。屋子正中有一只铁锅，锅里还在冒着热气，散发出一阵阵\n"
"肉香，锅下面竟还压着张字条。可怕的是，地上横七竖八倒着十几个黑衣大汉的尸\n"
"体，身子扭曲着，但脸上却带着种说不出的奇异的光辉，他们死得毫无痛苦，而且\n"
"还像是开心得很。\n"
""
        );
        set("exits", ([ 
		"south": __DIR__"desert_cabin",
		
	]));
        set("objects", ([
        	__DIR__"obj/guo":	1,
        	
	]) );
	set("item_desc", ([
        	"字条":	"字条上写着：\n"
"诸君不远千里而来，妾本当洁樽以待住蓖，怎奈属下顽劣，竟以凡俗之眼，视非凡\n"
"之人，此妾之过也，谨备肉羹一具，聊表妾歉疚之心，稍涤诸君子之征尘，盼诸君\n"
"子勿却是幸。龛中人睑衽百拜。\n",
        	"paper":"字条上写着：	\n"
"诸君不远千里而来，妾本当洁樽以待住蓖，怎奈属下顽劣，竟以凡俗之眼，视非凡\n"
"之人，此妾之过也，谨备肉羹一具，聊表妾歉疚之心，稍涤诸君子之征尘，盼诸君\n"
"子勿却是幸。龛中人睑衽百拜。\n",
        	"note":	"字条上写着：\n"
"诸君不远千里而来，妾本当洁樽以待住蓖，怎奈属下顽劣，竟以凡俗之眼，视非凡\n"
"之人，此妾之过也，谨备肉羹一具，聊表妾歉疚之心，稍涤诸君子之征尘，盼诸君\n"
"子勿却是幸。龛中人睑衽百拜。\n",
		"神龛":	"神龛却是空的。那石塑的佛像，竟已赫然不见了。\n",
		"龛":	"神龛却是空的。那石塑的佛像，竟已赫然不见了。\n",
		"kan":	"神龛却是空的。那石塑的佛像，竟已赫然不见了。\n",
	]) );
	
        set("coor/x",-90);
        set("coor/y",320);
        set("coor/z",0);
	setup();
	create_door("south","door", "木门", "north", DOOR_CLOSED);

}
