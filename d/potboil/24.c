#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"朝歌院"NOR);
	set("long","\n"
"\n"
"                        [1;37m◣                ◢\n"
"                        ║[1;31m■■■■■■■■[1;37m║\n"
"            ◢════════[1;36m 歌  朝 [1;37m════════◣\n"
"                [1;31m║[1;33m田田[1;31m║[1;33m田田[1;31m║[1;33m  田田  [1;31m║[1;33m田田[1;31m║[1;33m田田[1;31m║\n"
"                回回回回回回回回回回回回回回回回回回\n"
"      ◢■■■■■■■■■■■■■■■■■■■■■■■■■■◣\n"
"          ║[1;33m  田[1;31m║[1;33m田田[1;31m║[1;33m田田[1;31m║[1;30m│▉▉│[1;31m║[1;33m田田[1;31m║[1;33m田田[1;31m║[1;33m田  [1;31m║\n"
"        回回回回回回回回回回回[1;30m│▉▉│[1;31m回回回回回回回回回回回[2;37;0m[37m\n"
"       =====================◢════◣=====================\n"
"    ▄█≡≡≡≡≡≡≡≡≡◢◤════◥◣≡≡≡≡≡≡≡≡≡█▄\n"
"[2;37;0m  ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n"
"\n"
""
        );
	set("exits",([
		"northdown" : __DIR__"25",
	]) );

	set("objects", ([
	__DIR__"npc/cu" : 1,
					]) );

  	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",10);
	set("outdoors", "potboil");
	setup();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

/*

HIW
[1;37m
HIR
[1;31m
HIY
[1;33m
HIC
[1;36m
NOR
[2;37;0m
*/