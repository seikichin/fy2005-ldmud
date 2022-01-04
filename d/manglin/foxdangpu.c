//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
	set("short", "狐记当铺");
	set("long","此当铺是专为对面的狐狸窝所设，以方便手头不宽的嫖客和急于翻本的赌徒。出\n"
"海的商客们也经常光顾这里，把随身携带的贵重物品典当在此，等出海回来之后再赎\n"
"回，以防在海上丢失。当然狐狸窝里的姑娘们也经常来此典当或是卖掉客人们高兴之\n"
"余所赏赐的小玩意儿。当铺挂有牌（ｓｉｇｎ）一块。\n"
""
	   );
	set("exits", 
	   ([
	     "west" : __DIR__"southsearoad",
	    ]) );
	set("item_desc", 
	   ([
	     "sign": "\n"
"狐记当铺，目前我们提供的服务有：\n"
"\n"
"pawn	    典当货物。\n"
"value       估价货物。\n"
"sell        卖断货物。\n"
"redeem      赎回货物。\n"
"\n"
"童叟无欺！欢迎再次光临本店铺。^_^\n"
""
	    ]) );
	set("objects", 
	   ([
	     AREA_BAIYUN"npc/hockowner" : 1,
	    ]) );
	set("coor/x",70);
	set("coor/y",-230);
	set("coor/z",10);
	setup();
}