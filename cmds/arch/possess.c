 // possess.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        object ob; 
        if( !arg || me != this_player()) return 0;
        ob = present(arg, environment(me));
        if( !ob || !living(ob)){
                 notify_fail("这里没有这个生物。\n");
                 return 0;
                 }
        if( geteuid(ob) != geteuid(me) ){
                notify_fail( ob->name() + "的 euid 和你不合，无法进行附身。\n");
                return 0;
                }
        if( ob->query_temp("body_ob") ){
                 notify_fail( ob->name() + "已经被人附身过了。\n");
                 return 0;
                 }
        message_vision("$N化成一道光芒钻进$n体内。\n", me, ob);
        LOGIN_D->enter_world(me, ob, 1); 
        return 1;
} 
int help()
{
     write(funcall(#'read_file,"/help/cmds/arch/possess"));
        return 1;
}  
