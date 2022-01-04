
inherit ROOM;

void create()
{
	set("short", "董剑清家");
	set("long","青瓦红砖的围墙前，种著几株松树。两扇铜钉的大门紧紧关著。大门左右各卧\n"
"著一只石狮。石狮的神态安祥，就像看透了世上的一切，对任何事都不在意。清平\n"
"剑客一年到头很少在家，大都在四处云游。只在年底才回来与家人享受天伦之乐。\n"
""
	);
	set("exits", ([ 
		"west" : __DIR__"xzroad1",
	]));
	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
