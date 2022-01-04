// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm


inherit ROOM;
void create()
{
        set("short", "老鼠洞");
        set("long","    \n"
"[37m     \n"
"               _                       __\n"
"              /  \\                  /    \\ \n"
"             '     \\              /        \\ \n"
"            |       |Oo          o|         |\n"
"            `    \  |OOOo......oOO|   /      |\n"
"             `    \\OOOOOOOOOOOOOOO\//        /\n"
"               \ _o\OOOOOOOOOOOOOOOO//. ___ /\n"
"           ______OOOOOOOOOOOOOOOOOOOOOOOo.___\n"
"            --- OO'* `OOOOOOOOOO'*  `OOOOO--\n"
"                OO.   OOOOOOOOO'    .OOOOO o\n"
"                `OOOooOOOOOOOOOooooOOOOOO'OOOo\n"
"              .OO \"OOOOOOOOOOOOOOOOOOOO\"OOOOOOOo\n"
"          __ OOOOOO`OOOOOOOOOOOOOOOO\"OOOOOOOOOOOOo\n"
"         ___OOOOOOOO_\"OOOOOOOOOOO\"_OOOOOOOOOOOOOOOO\n"
"           OOOOO^OOOO0`(____)/\"OOOOOOOOOOOOO^OOOOOO\n"
"           OOOOO OO000/00||00\000000OOOOOOOO OOOOOO\n"
"           OOOOO O0000000000000000 ppppoooooOOOOOO\n"
"           `OOOOO 0000000000000000 QQQQ \"OOOOOOO\n"
"            o\"OOOO 000000000000000oooooOOoooooooO'\n"
"            OOo\"OOOO.00000000000000000000OOOOOOOO'\n"
"           OOOOOO QQQQ 0000000000000000000OOOOOOO\n"
"          OOOOOO00eeee00000000000000000000OOOOOOOO.\n"
"         OOOOOOOO000000000000000000000000OOOOOOOOOO\n"
"         OOOOOOOOO00000000000000000000000OOOOOOOOOO\n"
"         `OOOOOOOOO000000000000000000000OOOOOOOOOOO\n"
"           \"OOOOOOOO0000000000000000000OOOOOOOOOOO'\n"
"             \"OOOOOOO00000000000000000OOOOOOOOOO\n"
"  .ooooOOOOOOOo\"OOOOOOO000000000000OOOOOOOOOOO\n"
".OOO"""""""""".oOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
"OOO         QQQQO\"\'                     \`\"QQQQ\n"
"OOO\n"
"`OOo.\n"
"  `\"OOOOOOOOOOOOoooooooo....\n"
"\n"
"[0m\n"
"\n"
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"secret_room",
	]));
        set("item_desc",([
        	"down":	"洞下面黑咕隆咚什么也看不清，只有些悉悉索索的动静。\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/b_mice" : 1,
         ]) );

	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"恶狠狠地扑了上来。\n");
		else
			message_vision("$N匍匐在地上向下钻去。。。。\n",me);
			tell_object(me,"扑通一声，你从老鼠洞里掉了出来。\n\n\n");
			return 1;
	}
	return ::valid_leave(me,arg);
}
