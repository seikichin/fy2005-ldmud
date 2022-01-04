inherit ROOM;
void create()
{
        set("short", "小路");
        set("long","向东南的小路通向李家庄，庄主李大娘三年前搬到太平镇，在镇边买下了这一\n"
"座庄园。没有人知道大娘的来历，也没有人知道大娘在这儿干什么，不过即使是镇\n"
"上叱咤风云的武三爷，提起大娘来也会翘着大拇指说声“不简单”！\n"
""
        );
        set("exits", ([ 
		"west" : __DIR__"eroad1",
		"southeast" : __DIR__"gate",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",30);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}
