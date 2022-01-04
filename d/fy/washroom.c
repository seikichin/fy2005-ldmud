#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "私塾学堂");
    set("long","这里以前是一家洗衣店，是有钱人将衣服拿来浆洗的地方。自从这里的老板娘\n"
"去世了以后，有一个老人住了进来，把它改成一间私塾，但因为地区太乱，并没有\n"
"几个学生。门口有一个大木牌（ｓｉｇｎ）。\n"
);
    set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"ecloud1",
      ]));

    set("objects", ([
	__DIR__"npc/taipo" : 1,
      ]) );
    set("coor/x",80);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}



void init(){
    add_action("do_look","look");
}


int do_look(string arg){
    string msg;

    if (arg == "sign" || arg == "木牌"){
	msg = "\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;31m		天工开物，神鬼莫测[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"             \n"
"用私塾先生给的四个数和+,-,*,/,及()算出二十四。\n"
"\n"
"例如：	如果这四个数是：九,二,三,三. 请在一分钟内给出答案(answer)\n"
"	answer (9-2)*3+3\n"
"	第一个答对的奖励一百文。\n"
"             \n"
"";
	//	if (stringp(this_object()->query("question")))
			msg = msg + WHT"		现在的问题是" + query("question") + "\n"NOR;
		
		msg += "[0;1;37m────────────────────────────────[0m\n";
		write(msg);
		return 1;
	}        	
	return 0;
}
