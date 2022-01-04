// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string *tuned_ch;
    //considerate for bt and tt.
    if(arg=="bt") arg="bangtalk";
    else if(arg=="tt") arg="teamtalk";
	if (arg == "announce")
		return notify_fail("公示频道无法被关闭。\n");   

    tuned_ch = me->query("channels");
    if( !arg )
    {
        if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
            write("你现在并没有收听任何频道。\n");
        else
            write("你现在收听的频道：" + implode(tuned_ch, ", ") + "。\n");
    }
    else if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 )
    {
        write("关闭 " + arg + " 频道。\n");
        tuned_ch -= ({ arg });
        me->set("channels", tuned_ch);
    }
    else if(CHANNEL_D->valid_channel(me, arg))
    {
        write("打开 " + arg + " 频道。\n");
        tuned_ch += ({ arg });
        me->set("channels", tuned_ch);
    }
    else return notify_fail("没有这个频道。\n");

    return 1;
}

int help(object me)
{
    write("\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	tune [<频道名称>][0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令让你选择是否要收听某一频道的讯息，如果没有指定频道名称，\n"
"就会列出你目前收听中的频道，如果指定了频道，原来收听中的就会关掉，\n"
"反之打开。\n"
"\n"
"如果你对一个没有收听中的频道讲话，会自动将它打开。\n"
"要对一个频道讲话，只要用：\n"
"\n"
"<频道名称> <讯息> ....\n"
"\n"
"例子：\n"
"  chat hello everyone!\n"
"  \n"
"可以收听的频道有：\n"
"    info 【传闻】\n"
"    vote 【投票】\n"
"    chat 【闲聊】\n"
"    fy   【风云】\n"
"    new  【新手】\n"
"    gab  【市井】\n"
"    rumor【谣言】\n"
"    bangtalk/bt【帮会】\n"
"    teamtalk/tt【队伍】\n"
"    \n"
"[0;1;37m────────────────────────────────[0m \n"
""
	);
    if(wizardp(me))
        write("巫师可以收听的频道有：\n"
"    sys  【系统】\n"
"    qst  【任务】\n"
"    wiz  【巫师】\n"
"    debug  【调试】\n"		
"\n"
""
            );
	return 1;
}

