// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm

inherit ROOM;
void create()
{
        set("short", "老鼠洞");
        set("long","    \n"
"[37m     \n"
"	         ,;;;.;,;;;;,,   _\n"
"	      .;'             ''( );.\n"
"	    .;'                    o,'.\n"
"	    ;     )       .  .  ;      :;\n"
"	   ::       ~     ~( ~'';,,;\~~\n"
"	  : '. ,,, \'....; ',\n"
"	 '        ;..     ',,,'\n"
"	;           ;,,\n"
"	,;;;'\n"
"[0m\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"mice_room3",
	]));
        
        set("objects", ([
        	__DIR__"npc/m_mice" : 1,
         ]) );
         
	set("item_desc",([
        	"down":	"洞下面黑咕隆咚什么也看不清，只有些悉悉索索的动静。\n",
        ]));
	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-15);
	setup();
}


int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"恶狠狠地扑了上来。\n");
		else
			message_vision("$N匍匐在地上向下钻去。。。。\n",me);
			return 1;
	}
	return ::valid_leave(me,arg);
}
