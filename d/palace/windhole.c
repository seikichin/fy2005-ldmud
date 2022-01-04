
inherit ROOM;

void create()
{
        set("short", "风穴");
        set("long","山窟外雾色朦胧，鬼气森森。山窟内更是阴暗，几乎是伸手难见五指.洞内寒风\n"
"如刀，呼啸不绝。深呼一口气，只觉的空气中充满了血腥，一种不详的感觉涌上了心\n"
"头。\n"
""
        );
        set("exits", ([ 
  "east" : __DIR__"interroad",
  "west" : __DIR__"ghost",
]));
        set("objects", ([
        __DIR__"obj/hulu" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",10);

	setup();

}

void reset(){
	object obj;
	
	::reset();
	if(!present("hulu", this_object())){
		obj = clone_object(__DIR__"obj/hulu");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}	
	return;
}
