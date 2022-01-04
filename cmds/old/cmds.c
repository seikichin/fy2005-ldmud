// help.c

#include "/doc/help.h"
#include <ansi.h>
#include <input_to.h>

inherit F_CLEAN_UP;

void selete_main(string num,object ob);
void back_off(string num,object ob);
void quit_help(object ob);

int main(object me, string arg)
{
        int i;
        string file, map, *search;
        object ob;
        ob = this_player();

        write(CLR);
        write(read_file("/doc/help/cmds_main.txt"));
        input_to("selete_main",INPUT_PROMPT,"",ob);
        ob->set_temp("block_msg/all",1);
        return 1;
}

void selete_main(string num,object ob)
{
        
        string *code = ({"1","2","3","4","5","6","7","8"});
                
        if(member_array(num, code) != -1)
        {
                ob->delete_temp("block_msg/all");
                write(CLR);
                write(read_file("/doc/help/help/cmds_"+num+".txt"));
                input_to("back_off",INPUT_PROMPT,"",ob);
        }
        else if( num == "q" || num == "Q" || num == "0") quit_help(ob);
        else
        {
                ob->delete_temp("block_msg/all");
                write(HIR"\n    对不起，没有这个选项！您可以选择：\n"NOR);
                write(CYN"  　１- 8 相关的命令说明　　0、退出帮助\n"NOR);
                write(CYN"\n    请输入选择项（1-8 或 0）："NOR);
                ob->set_temp("block_msg/all");
                input_to("selete_main",INPUT_PROMPT,"", ob);
        }
}

void back_off(string num,object ob)
{
	write(CLR);
        write(read_file("/doc/help/cmds_main.txt"));
        input_to("selete_main", 4,ob);
        ob->set_temp("block_msg/all",1);
}

void quit_help(object ob)
{
        ob->delete_temp("block_msg/all");
     	write(HIC"\n 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！\n\n"NOR);
        return;
}

int help(object me)
{
        write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 		cmds[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个命令给出风云中玩家可以使用的所有命令列表，\n"
"请按照屏幕提示输入选项以进入子菜单。\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
""
        );
        return 1;
}

