// chpasswd.c
// add by Karry@FY3
inherit F_CLEAN_UP;
#include <login.h>


void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;
        if(!arg||sscanf(arg,"%s %s",id,password)!=2){
                 return notify_fail("用法:chpasswd ID 新密码\n请慎用此指令！\n");
                 }
        ob=find_player(id);
        if(!ob)
        {
        ob = clone_object(LOGIN_OB);
        ob->set("id",id);
    	
        if( !ob->restore() ){
                return notify_fail("没有这个玩家。\n");
                 }
 
        else
                {                                    
           ob->set("password",crypt(password,0));
           tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                     + ")的密码已经更改为："+password+"。\n");
 
                    log_file( "changepw", sprintf("%s %s(%s)修改了%s(%s)的密码\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
                }
        }
        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
                link_ob->set("password",crypt(password,0));
                link_ob->save();
                tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                        + ")的密码已经更改为："+password+"。\n");
                return 1;
        }
        else{
             return   notify_fail("错误。无法进行修改。\n");
                 }
        return 1;
}


int help(object me)
{
     write(funcall(#'read_file,"/help/cmds/adm/chpasswd"));   
    return 1;
}
