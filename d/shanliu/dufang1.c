// Room: dufang1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "金胡子赌坊");

	set("long","赌坊的屋子虽然很大，看来还是烟雾腾腾的，到处都挤满了人。各式各样的人，\n"
"大多数都很紧张，有几个不紧张的，也只不过是在故作镇定而已，其实连小衣都只\n"
"怕已被汗水湿透。真正不紧张的怕是只是一个，那便是老板金大胡子了。赢家永远\n"
"是他,这道理他是再清楚不过了。门上有匾（ｓｉｇｎ）一块。\n");
	set("exits",([
	"east":__DIR__"pomen",
	]) );
	set("objects", ([
	__DIR__"npc/jinhuzi" :1,
	__DIR__"npc/haoke" :2,
	]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("indoors", "shanliu");
        set("item_desc", ([
                "sign": "\n"
"\n"
"本赌坊赌大不赌小，最少赌注二十两黄金！\n"
"\n"
"骰子的赌法：\n"
"\n"
"ｂｅｔ　＜种类＞　＜金量＞\n"
"\n"
"种类：　０，１，２，３到１８\n"
"０：　		赌小	（３－１０）	一赔一\n"
"１：  		赌大	（１１－１８）	一赔一\n"
"２：　		赌围骰	（三粒骰子同点）一赔三十六\n"
"３－１８	赌单点  		一赔八\n"
"\n"
"例子：\n"
"ｂｅｔ　０　２０\n"
"赌二十两黄金在小上\n"
"\n"
""
        ]) );
	setup();
	replace_program(ROOM);
}
