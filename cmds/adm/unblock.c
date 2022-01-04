#include <login.h>
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;

        if(!arg){
                return notify_fail("请用help查看此指令用法！\n");
                 }
        ob=find_player(arg);
        if(ob){
		return notify_fail("此指令只能对离线玩家使用。\n");

			 }

		ob = FINGER_D->acquire_login_ob(arg);
    	
        if(!ob){
              return notify_fail("没有这个玩家。\n");
              }
			
		if (!ob->query("blocked")){
             return notify_fail("这个玩家不需要执行解锁操作。\n");
              }
	
		ob->delete("blocked");
		ob->save();
		destruct(ob);
		write("UNBLOCK 完毕 Ok.\n");
		
        return 1;
}


int help(object me)
{
       write(funcall(#'read_file,"/help/cmds/adm/unblock"));
    return 1;
}
