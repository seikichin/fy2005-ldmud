
inherit ROOM;

void create()
{
        set("short", "羊肠小道");
        set("long","大昭寺的北面是恰克卜里山，一条山间小路弯弯曲曲地向山顶延伸，道旁的茅\n"
"草高达五尺，遮住了天光，山幽中的一切都显的阴森幽暗，偶尔传来几声野兽的啸\n"
"叫。除了砍柴的樵夫，这儿很少有人涉足。\n"
""
        );
        set("exits", ([ 
		  "southdown" : AREA_GUANWAI"citygate",
		  "north" : __DIR__"smallroad2",
	]));
        set("outdoors", "resort");

	set("coor/x",40);
	set("coor/y",-60);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

