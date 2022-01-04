// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   mapping tell=([]);
	if (!arg) {
		write("你自言自语不知道在说些什麽。\n");
		message("sound", me->name() + "自言自语不知道在说些什麽。\n",
			environment(me), me);
		return 1;
	}
	if( ({int})me->query("kee") < ({int})me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}
 
	write( CYN "你说道：" + arg + "\n" NOR);
	 tell=([
  	  "channel":"Local",
  	  "talker":me->name(1),
  	  "text":wrap("你说道：" + arg + "\n",48),
		  	  ]);
      me->process_gmcp(tell,"Comm.Channel","Text");
	message("sound", CYN + me->name() + "说道：" +  arg + "\n" NOR,	environment(me), me);

	// The mudlib interface of say

	return 1;
}

int help (object me)
{
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	 say <讯息>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
" \n"
"说话，所有跟你在同一个房间的人都会听到你说的话。\n"
" \n"
"注: 本指令可用 ' 取代.\n"
"\n"
"[0;1;37m────────────────────────────────[0m    \n"
""
	);
	return 1;
}
