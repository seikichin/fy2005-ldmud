inherit ROOM;
void create()
{
    set("short", "风云布铺");
    set("long","布铺里摆满了绫罗绸缎，这里专门订作、裁剪、改装各种鞋，帽，衫。老裁缝\n"
"做的衣服不但款式新颖，而且经久耐穿。风云城里老老少少们穿的大部份都是来自\n"
"这儿。门口挂了一个大牌子（ｓｉｇｎ）。\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"huanyun5",
      ]));
    set("objects", ([
	__DIR__"npc/cloth" : 1,
      ]) );
    set("item_desc", ([
	"sign": "\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m		老字号布铺[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"\n"
"[0;1;33m　　出售各种小儿衣物，新手可用，物美价廉，童叟无欺！[0m\n"
"\n"
"　　你可以使用[0;1;32mlist[0m指令查看这里出售的衣物，用[0;1;32mbuy[0m购买。\n"
"\n"
"[0;1;37m────────────────────────────────[0m\n"
""
      ]) );

    set("coor/x",40);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}

// 凝輕·dancing_faery@hotmail.com
