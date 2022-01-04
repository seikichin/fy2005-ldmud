#include <login.h>
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}
int _exec(object ob1, object ob2)
{
return efun::exec(ob1,ob2);
}

int main(object me, string arg)
{
        object ob,link_ob;

        if(!arg){
                return notify_fail("请用help查看此指令用法！\n");
                 }
       write("exec\n");          
}

