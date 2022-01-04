// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long","大雄殿通往六祖殿的捷径，红木为栏，琉璃做顶，曲折回绕，妙不可言，扶手\n"
"之上雕花切字，两边廊壁之上尽是题字题诗，历代僧人多有把禅机写于此间者。这\n"
"里墙上一首特别引人注目。相传为神秀所书“身是普提树，心如明镜台，时时勤拂\n"
"拭，莫遣有尘埃。”\n"
""
        );
        set("exits", ([ 
  "eastup" : __DIR__"daxiong",
  "west" : __DIR__"liuzu2",
]));
	
	   set("objects", ([
       	__DIR__"npc/monk20b1" : 1,
       	__DIR__"npc/monk20c1" : 1,
       ]) );
	
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
