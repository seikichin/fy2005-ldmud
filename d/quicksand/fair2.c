
inherit ROOM;

void create()
{
        set("short", "集市");
        set("long","集市上卖的都是些过沙漠的必备物品，骆驼，水袋、粮食、宿具，以及一些零\n"
"零碎碎，看来虽无用，到时都有用的东西。大多数商人都将他们最好的货色陈列出\n"
"来，来引诱路人的眼睛。他们也在瞧着路上的行人，那眼色就好像行人瞧货物一样，\n"
"路人的兴趣在他们的货物，他们的兴趣却在路人的钱袋。\n"
""
        );
        set("exits", ([ 
  		"north" : __DIR__"fair",
 		"west": __DIR__"house",
 		"east": __DIR__"yizhan",
 		"south": __DIR__"jadestore",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
        	__DIR__"npc/trader2": 	1,
        	__DIR__"npc/trader3":   1,
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}

