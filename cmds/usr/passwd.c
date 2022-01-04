// passwd.c
#include <input_to.h>

inherit F_CLEAN_UP;
protected void get_old_pass(string pass, object ob);
protected void get_new_pass(string pass, object ob);
protected void confirm_new_pass(string pass, object ob, string new_pass);
int main(object me, string arg)
{
        object ob;

        if( me != this_player() ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        write("为了安全起见，请先输入您原来的密码：");
        input_to((: get_old_pass($1, ob) :),INPUT_NOECHO|INPUT_PROMPT,"");
        return 1;
}

 protected void get_old_pass(string pass, object ob)
{
        string old_pass;

        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("密码错误！\n");
                return;
        }
        write("请输入新的密码：");
        input_to((:get_new_pass($1, ob):), INPUT_NOECHO|INPUT_PROMPT,"");
}

protected void get_new_pass(string pass, object ob)
{
	if(!LOGIN_D->check_legal_password(ob,pass))
	return ;
        write("\n请再输入一次新的密码：");
        input_to((:confirm_new_pass($1, ob, crypt(pass,0)):), INPUT_NOECHO|INPUT_PROMPT,"");
}

protected void confirm_new_pass(string pass, object ob, string new_pass)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
                return;
        }
        seteuid(getuid());
        if( !ob->set("password", new_pass) ) {
                write("密码变更失败！\n");
                return;
        }

        ob->save();
        write("密码变更成功。\n");
}

int help(object me)
{
        write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	passwd[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令可以修改你的人物密码。\n"
"\n"
"[0;1;37m────────────────────────────────[0m \n"
);
    return 1;
}
 
