#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{

	if (!arg) 
		return notify_fail("此命令需要参数，请参见ｈｅｌｐ　ａｆｋ。\n");
		
	if (!me->query("afk_msg"))
		me->set("afk_msg",WHT"对不起，请稍后联系。\n"NOR);
	
	if(arg == "on") {
		me->set("env/afk",1);
		tell_object(me,WHT"你现在设定为离机状态。\n"NOR);
		tell_object(me,WHT"你的自动答复信息为："+me->query("afk_msg")+"。\n"NOR);
		return 1;
	}
	
	if (arg=="off") {
		me->set("env/afk",0);
		tell_object(me,WHT"你取消了离机状态。\n"NOR);
        	return 1;
        }
	
	me->set("afk_msg",arg);
	tell_object(me,WHT"设定你的离机自动答复信息为："+me->query("afk_msg")+"。\n"NOR);
	return 1;
}


int help(object me)
{
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式：ａｆｋ <讯息>[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"\n"
"这个指令让你设定在发呆状况下的自动答复，使用方法为：\n"
"\n"
"ａｆｋ　ｏｎ　　打开自动答复。\n"
"\n"
"ａｆｋ　ｏｆｆ　关闭自动答复。\n"
"\n"
"ａｆｋ　＜自定义信息＞　　定义自己的自动答复信息。\n"
"\n"
"举例：\n"
"\n"
"张三设定ａｆｋ　ｏｎ，当李四ｔｅｌｌ　ｚｈａｎｇｓａｎ　嗨，你好。\n"
"张三自动答复李四：“我去吃饭了，过会儿再聊。”\n"
"[0;1;37m────────────────────────────────[0m\n"
""
	);
	return 1;
}
