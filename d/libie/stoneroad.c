// Room: stoneroad.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "石板路");

	set("long","小县城中便只有一条石板路可供路人来往，路的两边零零星星有几户人家，石\n"
"板上青苔厚绿，一不小心便会摔个跟头。远处是一片梅林，空气中飘荡着若有若无\n"
"的梅子初熟的味道。	\n");

	set("type","road");
	set("exits",([
	"west":__DIR__"stoneroad2",
	"north":__DIR__"yard",
    "east":__DIR__"stoneroad3",
	]) );
	//}}
		    	set("objects", ([
        __DIR__"npc/huasiye" : 1,
            ]) );
        set("outdoors", "libie");
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);

	setup();
	replace_program(ROOM);
}
