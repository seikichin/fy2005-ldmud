// Room: trap.c
inherit ROOM;

void create()
{
	set("short", "陷井");

	set("long","这是一个深深的葫芦型的陷井，井壁潮湿而又光滑。井底甚为宽敞。\n"
"你脚边是三具已经腐烂的尸体，四周还散布着不少黄白之物，显然\n"
"是饿虎山上的强盗们时不时在井口方便的结果。旁边似乎还有几只\n"
"大老鼠，正在黑暗中窥视着你，仿佛在等着将你作为下一顿美餐。\n");
	set("long_night", "\n"
"这是一块空地，到了晚上就更不要指望看见什么。\n");

	set("type","street");

	setup();
	replace_program(ROOM);
}
