inherit ROOM;

void create()
{
	set("short", "碎石小路");

	set("long","这条碎石小路往西便是“有竹无肉轩”了，东侧是富贵如意厅。路上生满了青\n"
"苔，一不当心就会跌倒，两侧不知名的野花开得倒也茂盛，淡淡的散发着一种清新\n"
"的花香。草窠中偶尔传来一两声蟋蟀的叫声。一抬头，可以看见几个或是蜈蚣状，\n"
"或是老鹰状的风筝高高飞舞在蓝天白云中。\n");

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"fuguitin",
        "west":__DIR__"wuzhuxuan",
	]) );

        set("objects" , ([
	    __DIR__"obj/flower" : 1,
        ]));
	set("coor/x",0);
	set("coor/y",210);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
