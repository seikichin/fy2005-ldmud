//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "一叶堂");
    set("long","一叶斋是白云岛上的一家书院，一尘不染。一位庄重严肃的老者坐在太师椅上\n"
"讲学，那就是叶老夫子先生了。在他的两侧坐满了求学的学生。一张古意盎然的书\n"
"案放在朱先生的前面，案上摆着几本翻开了的线装书籍。堂中肃穆，间或传来翻书\n"
"和落笔的刷刷之声。\n"
);
    set("exits",
      ([
	"south" : __DIR__"skystreet4",
      ]));
    set("objects",
      ([
	__DIR__"npc/oldye" : 1,
	__DIR__"obj/desk": 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-150);
    set("coor/z",30);
    setup();

}

void reset() {
    int num = 2;
    object obj, *inv ,desk;

    :: reset();

    desk = present("book desk", this_object());
    if (!desk)	return;

    inv = all_inventory(desk);
    foreach (object ob in inv) 
    {
	if (userp(ob)) continue;
	if (ob->query("id") == "ethic book") destruct(ob);
    }
    while (num--) 
    {
	obj = clone_object(BOOKS"skill/daode_30");
	obj->move(desk);
    }
}
