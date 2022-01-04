inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "杜埔草堂");
        set("long","杜甫因避安史之乱流亡到成都,在友人的帮助下盖起了这座茅屋，便是他\n"
"诗中提到的\"万里桥西宅，百花潭北庄\"的成都草堂。草堂内楠木参天，梅竹\n"
"成林，溪水婉蜒，桥亭相间，花径柴门，曲径通幽，园林格局典雅而幽美。\n"
"正中是杜甫立像，堂内陈列有历代名人题写的楹联、匾额。\n"
        );
	set("exits",([
  		"west" : __DIR__"beidajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}