// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "鬼门关");
        set("long","猛一惊醒，不觉身在鬼门关，高大的城墙边渭水环绕，阴气森森，几个面目狰\n"
"狞的牛头，马面手持武器把守城门，勾死人手持铁链正在拖拽着几个人影走了进去\n"
"．．．．．．．，城门楼上高悬一幅牌匾：\n"
"[31m\n"
"\n"
"			鬼门关\n"
"[32m\n"
""
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"naihe",
		"east" : __DIR__"aihe2",
        ]) );
        set("objects", ([
		__DIR__"npc/panguan" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}
