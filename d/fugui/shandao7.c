inherit ROOM;

void create()
{
	set("short", "白玉山路");
	set("long","这是一条通往富贵山庄的崎岖山道。道旁半枯的秋草在夕阳下看来宛如黄金，\n"
"遍地的黄金石板砌成的小径斜向上方伸展，宛如黄金堆中的一串白玉。风在吹，鸟\n"
"儿在啼啾低语，混合成种比音乐还美妙的声音。它美妙得宛如情人在耳畔低语。满\n"
"山弥漫着花的香气、草的香气、风的香气。但凡漫步于此的游人大都不自禁的停下\n"
"了脚步，驻足小憩.\n");

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "eastdown":__DIR__"shandao8",
        "northup":__DIR__"shandao6",
	]) );

	set("coor/x",10);
	set("coor/y",130);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
