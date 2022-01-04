inherit ROOM;

void create()
{
	set("short", "吉祥钱庄");

	set("long","虽然说现在中原各省的钱庄基本被南宫家族所垄断，但在吉祥镇上，人们还是\n"
"对自家镇上这间开了百余年的老字号的吉祥钱庄青眼有加，因此这儿平常生意还算\n"
"不错，老板财叔总是乐呵呵地坐在柜台后眯着眼睛数着要兑换的银钱。门上贴着块\n"
"牌子（ｓｉｇｎ）。\n");

	set("type","house");
	set("exits",([
		"east":__DIR__"xiaojie4",
	]) );
	set("objects",([
		__DIR__"npc/cai":1,
	]) );
	set("item_desc", ([
        	"sign": "\n"
"这里是钱庄，目前我们提供的服务有：\n"
"\n"
"convert     兑换钱币。\n"
"withdraw    提取存款。\n"
"deposit     存入钱币。\n"
"balance     察寻存款。\n"
"loan        向钱庄借钱。\n"
""
        ]) );

	set("coor/x",10);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}