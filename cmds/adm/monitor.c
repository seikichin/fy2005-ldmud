#include <login.h>
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        int num;
        string name;

        if(!arg){
        return notify_fail("请用help查看此指令用法！\n");

        	 }
        
        if(sscanf(arg,"%s %d", name,num)!=2){
        	return notify_fail("请用help查看此指令用法！\n");
        	}
                
        ob=find_player(name);
        if(!ob){
			return notify_fail("此指令只能对在线玩家使用。\n");
	
			 }

		if (num>5 || num<0){
			return notify_fail("请用help查看此指令用法！\n");
	
			}
			
        ob->set("MONITORING", num);
		if (!num)
			ob->delete("MONITORING");
		
		write(sprintf("开始对%s(%s)进行%d级纪录。\n", ob->name(1),ob->query("id"),num));
		return 1;
		        
}


int help(object me)
{
    write(funcall(#'read_file,"/help/cmds/adm/monitor"));
    return 1;
}
