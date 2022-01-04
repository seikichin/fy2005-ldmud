#include <room.h>
inherit ROOM;

void create()
{
  set("short","墙外小道");
  set("long","\n"
"岱庙方圆数里，四周皆有城墙，墙高三长，上有角楼、门楼。墙外是野草地，\n"
"风过簌簌作响，颇是荒凉，原本少有人至。只是近年来西方神教在岱庙建立总坛后，\n"
"寻常人等难以进入，想上泰山也只有从城墙外绕路了。\n"
);
  	set("exits",([
        	"east":__DIR__"houzai",
         	"west":__DIR__ "w_wall_3",
        ]));
        set("objects", ([
        
        ]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-15);
	set("coor/y",20);
	set("coor/z",0);
	setup();
  	
}
