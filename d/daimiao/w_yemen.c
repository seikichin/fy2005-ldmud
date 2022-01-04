#include <room.h>
inherit ROOM;

void create()
{
  set("short","西掖门");
  set("long","\n"
"正阳门两侧的小门是掖门。岱庙大院四周围筑城墙，周环三里。庙有八个门，\n"
"南向五门，中为正阳，两侧为掖门；掖门两侧，东为仰高，西为见大。东门名东华，\n"
"又称青阳；西门名西华，又称素景，北门叫厚载。\n"
);
  	set("exits",([
        	"east":__DIR__"zhengyan",
         	"west":__DIR__"jianda",
         	"southeast": __DIR__"daimiao",
        ]));
        set("objects", ([
        
        ]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-20);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  	
}
