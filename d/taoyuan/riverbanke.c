inherit __DIR__"no_killing_place";

void create()
{
    set("short", "桃源亭");
    set("long","四周的草坪修剪得很整齐，沿着河岸生长着一些水生植物，有浮萍，水仙，还\n"
"有几丛芦苇，草坪中央是一座[37m亭台[32m，不远处的草坪上错落有致地摆着有山石树木，\n"
"再过去就是一座白墙粉瓦的小庭院。几棵修竹从粉墙上探出头随风云摇动，四周静\n"
"悄悄的，偶尔能听到河西传来的狗叫声。\n"
""
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"bridge",
        ]));

	set("objects", ([
		__DIR__"npc/tingzhu" : 1,
	]) );
	
	set("item_desc", ([
		"亭台" : "这里是风云中志同道合之士结义的地方。\n"
"＊结义（ｊｉｅｙｉ）：要求男１４、女１２以上，不限男女\n"
"＊解除结义之情：有两种途径\n"
"（１）割袍断义（ｊｕｅｊｉａｏ）：要求双方在场\n"
"（２）背弃（ｂｅｔｒａｙ）：\n"
"当一方退出风云（如自杀、清档等）或长期不在线（６０天以上），\n"
"则另一方可单方面解除结拜之情。具体请参看有关帮助文件。	\n\n",
		"pavilion" : "这里是风云中志同道合之士结义的地方。\n"
"＊结义（ｊｉｅｙｉ）：要求男１４、女１２以上，不限男女\n"
"＊解除结义之情：有两种途径\n"
"（１）割袍断义（ｊｕｅｊｉａｏ）：要求双方在场\n"
"（２）背弃（ｂｅｔｒａｙ）：\n"
"当一方退出风云（如自杀、清档等）或长期不在线（６０天以上），\n"
"则另一方可单方面解除结拜之情。	具体请参看有关帮助文件。\n\n",
		"ting" : "这里是风云中志同道合之士结义的地方。\n"
"＊结义（ｊｉｅｙｉ）：要求男１４、女１２以上，不限男女\n"
"＊解除结义之情：有两种途径\n"
"（１）割袍断义（ｊｕｅｊｉａｏ）：要求双方在场\n"
"（２）背弃（ｂｅｔｒａｙ）：\n"
"当一方退出风云（如自杀、清档等）或长期不在线（６０天以上），\n"
"则另一方可单方面解除结拜之情。	具体请参看有关帮助文件。\n\n",
	]) );
	
	set ("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",70);
	set("coor/y",0);
	set("coor/z",0);
    setup();

}


