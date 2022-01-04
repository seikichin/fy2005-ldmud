// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","中天门");
  set("long","\n"
"中天门位泰山正中，地处黄岘岭，中溪在这蜿蜒而下，以甘冽的清泉和悦耳的\n"
"泉声迎接奋力登山的游人。一个巨大的门楼是中天门的胜景，依傍着嶙峋的山石，\n"
"石雕门楼是那么的精巧，但又浑然天成，历代经无数能工巧匠的描绘，中天门已经\n"
"成为了一个永远留传的艺术史诗。再往上便是出名的胜景---云步桥。\n"
);
  	set("exits",([
	"down" : __DIR__"butian",
	"up" : __DIR__"buyun",
               ]));
        set("objects", ([
        	"/obj/npc/oldbeggar" : 2,
        	"/obj/npc/inform_beggar": 1,
        	__DIR__"npc/honglianhua" : 1,
                        ]) );

        set("outdoors", "taishan");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",60);
	setup();
  	replace_program(ROOM);
}
