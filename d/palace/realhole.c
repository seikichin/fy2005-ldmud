
inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long","奔入石洞中，但觉酷热全消，迎面吹来一阵寒风。越往里走寒风更烈，呼啸之\n"
"声，连绵不绝。这寒风的呼啸，听来竟犹如战场上的杀戮之声一般，使得这阴森幽\n"
"暗的洞窟之中，充满了恐怖与杀机。\n"
""
        );
        set("exits", ([ 
  "east" : __DIR__"holeopen",
  "west" : __DIR__"interroad",
]));
        set("objects", ([
        __DIR__"obj/needle" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",10);

	setup();
}
void reset(){
	object obj;
	
	::reset();
	if(!present("needle", this_object())){
		obj = clone_object(__DIR__"obj/needle");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}	
	return;
}
