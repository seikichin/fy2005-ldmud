inherit ROOM;

void create()
{
	set("short", "风云道");

	set("long","“一入风云岁月催”，这儿是连接[33m沉香镇[32m和[33m南海[32m的风云道，暗褐色的道路，从\n"
"这里开始婉蜒伸展，穿过翠绿的树林，沿着湛蓝的湖水，一头伸展向闹市，一头绕\n"
"过黑漆漆的森林通向远方。远山在阴瞑的天色中看来，仿佛在雾中，更加美丽神秘。\n");

	set("type","road");
	set("exits",([
        "northwest":__DIR__"fydao2",
        "east":		AREA_MANGLIN"plainroad",
		]) );
        set("outdoors", "chenxiang");
	set("coor/x",280);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
