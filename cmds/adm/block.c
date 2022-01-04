#include <login.h>
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;

        if(!arg){
                return notify_fail("请用help查看此指令用法！\n");
                 }
        ob=find_player(arg);
        if(!ob){
		return notify_fail("此指令只能对在线玩家使用。\n");

			}

        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
			link_ob->set("blocked",1);
			link_ob->save();
			destruct(ob);
			write("BLOCK　Ok.\n");
			return 1;
        }
        return notify_fail("Unknown error.\n");

}


int help(object me)
{
        write(funcall(#'read_file,"/help/cmds/adm/block"));
    return 1;
}
