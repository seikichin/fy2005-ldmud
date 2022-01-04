// Silencer@fy4 workgroup
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"故乡之路"NOR);
	set("long","长长的甬道到这里突然一亮，原来是一个十字叉路，正前方的路平坦光明，而\n"
"其他三条路或崎岖，或险峻，或荆棘丛生。。。四块古老的木牌插在各自的路口，\n"
"路的远方究竟是什么在等待着你？究竟该选择哪一条呢？（请选择风云中的民族，\n"
"命令为[37mｓｅｔｒａｃｅ[32m，后跟你希望的民族选项[1;32m汉族、满族、蒙古族、苗族[0;32m，各民\n"
"族的差异参阅[37mｈｅｌｐ　ｎｅｗｂｉｅ[32m中的民族篇（选项7）。）\n"
""
	);
	set("exits", ([
//  		"down" :  "/d/fy/fqkhotel",
		 "down" :  __DIR__"newbie4",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",850);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}


void init(){
	add_action("do_setrace", "setrace");
}


int valid_leave(object me, string dir) {

	if (dir == "down")
	if ( !me->query_temp("race_setup"))
		return notify_fail("请在进入风云世界前选定一个民族。\n"
"格式： setrace <民族名（汉字或拼音）>\n");
	
	return ::valid_leave(me, dir);
}

int do_setrace(string arg)
{
	object me;
	
	me = this_player();
	
	if( !arg ) 
		return notify_fail("你希望加入哪一个民族？\n"
"格式： setrace <民族名（汉字或拼音）>\n");
		
	switch (arg) {
	case "汉族" :
	case "hanzu" :
			me->set("national","汉族");
			break;
        case "满族" :
        case "manzu" :
                        me->set("national","满族");
                        break;
        case "蒙古族" :
        case "mengguzu" :
                        me->set("national","蒙古族");
                        break;
        case "苗族" :
        case "miaozu" :
                        me->set("national","苗族");
                        break;
        default :
			return notify_fail("没有这个民族\n"
"格式： setrace <民族名（汉字或拼音）>\n");

	}
	write("你决定投生于"+ me->query("national") + "。\n");
	me->set_temp("race_setup", 1);
	return 1;
}

