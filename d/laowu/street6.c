
inherit ROOM;

void create()
{
        set("short", "神秘冰河");
        set("long","阳光下的冰河，看起来辉煌壮观。冰结十丈，坚如钢铁。这里离河岸很近，冰\n"
"的颜色却好象比别处还要深暗些。一段枯树露在河面上，想必是开始封江的时候倒\n"
"下来的。枯枝也不知被谁削平了，树干却还有一小半露在河面外。\n"
""
        );
        set("exits", ([ 
  "north" : __DIR__"street3",
]));
        set("outdoors", "laowu");

	set("coor/x",31);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

