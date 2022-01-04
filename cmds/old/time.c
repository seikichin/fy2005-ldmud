// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("现在是" + NATURE_D->game_time() + "。\n");
	return 1;
}

int help(object me)
{
     write("\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	time[0m\n"
"[0;1;37m────────────────────────────────[0m   \n\n"
"这个指令让你(玩家)知道现在的时辰。\n"
"[0;1;37m────────────────────────────────[0m\n"

    );
    return 1;
}
