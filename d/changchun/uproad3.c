// searoad.c
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long","小路曲曲折折返向山峰，一路上但见青翠的山林中，种满了五彩缤纷的花朵。\n"
"林木间，花光间，不时可瞧见亭台楼阁，翩翩人影，当真犹如一群仙女倘徉在这世\n"
"外仙山中。\n"
""
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl" : 1,
        ]) );
        set("exits", ([ 
	  	"east" : __DIR__"platform",
  		"westdown" : __DIR__"uproad2",
	]));
        set("outdoors", "tieflag");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}

