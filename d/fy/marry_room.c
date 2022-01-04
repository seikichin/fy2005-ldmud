// marry_room.c
#include <ansi.h>
// tie@fengyun
#include <room.h>
inherit ROOM;

void create()
{
    set("short", HIM"鸳鸯亭"NOR);
    set("long","你现在正站在鸳鸯亭里，这里是专门替人缔结婚约和解除婚约的地方，城里所\n"
"有的夫妇都是在这里喜结良缘的，就连附近镇子也有许多慕名而来的年青人．靠近\n"
"门口的地方有一块乌木雕成的招牌（ｓｉｇｎ）。\n"
);
    set("exits", ([
	"east"          : __DIR__"huanyun4", 
      ]) );

    set("item_desc", ([
"sign": "\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m		鸳鸯亭提供业务[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"\n"
"\n"
"＊缔结婚姻（ｍａｒｒｙ）：要求男１４、女１２以上\n"
"\n"
"＊解除婚约：有两种途径\n"
"（１）离婚（ｄｉｖｏｒｃｅ）要求双方在场自愿\n"
"（２）遗弃（ｄｅｓｅｒｔｅｄ）\n"
"当一方退出风云（如自杀、清档等）或长期不在线（６０天以上），\n"
"则另一方可单方面以被遗弃提出解除婚约。\n"
"\n"
"\n"
"[0;1;37m────────────────────────────────[0m\n"
""
      ]) );
      
    set("objects", ([
	__DIR__"npc/mei_po" : 1,
      ]) );

    set("coor/x",40);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();

}
