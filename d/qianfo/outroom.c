// 茅屋外
// QC and modified by Tie
inherit ROOM;

void create()
{
        set("short", "茅屋外");
        set("long","前面是处山谷，郁郁苍苍，满山树木。西面山坡上，竟简陋的建有三间歪歪侧\n"
"侧的茅屋，茅屋前还悬着面木牌（ｓｉｇｎ）。一阵阵肉香自茅屋中飘散而出，窗\n"
"户里似乎有人探首出来，向你瞧了几眼。\n"
""
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"maoroom",
  "southdown" : __DIR__"road1",
]));

        set("item_desc", ([
                "sign": "		\n"
"					小\n"
"					小\n"
"					少\n"
"					林\n"
"					寺\n"
        ]) );
        set("outdoors", "qianfo");
	set("coor/x",100);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_hit","strike");
}

int do_hit(string arg)
{
	object ob;
if( (arg == "sign" || arg == "木牌") && query("already") < 10) 
{
	tell_object(this_player(),"你对木牌猛击一掌，将它打碎一小块！\n");	
	ob=clone_object(AREA_TIEFLAG"obj/woodpiece");
	ob->move(this_object());
	this_object()->add("already",1);
	return 1;
	}
	return 0;
}
void reset()
{
:: reset();
delete("already");
}

