
inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long","这是一条长长的甬道，甬道两旁嵌有铜灯。甬道斜斜地伸如地下，不知有多长，\n"
"也不知伸向何处，但两壁铜灯俱都擦得极为光亮，显见此地经常有人行走。\n"
""
        );
        set("exits", ([ 
  "east" : __DIR__"secretpath1",
  "west" : __DIR__"kengdi",
]));

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

