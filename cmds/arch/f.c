// haha
// f.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        mixed msg;
        string target;

        if (({string})SECURITY_D->get_status(me) != "(admin)")
                return 0;

        if (! arg) { notify_fail("你要控制谁做什么？\n");return 0;}

        if (sscanf(arg, "%s to %s", target, arg) != 2 ||
            ! objectp(ob = find_player(target)) &&
            ! objectp(ob = present(target, environment(me))) &&
            ! objectp(ob = find_real_living(target)))
        {
                // 没有这个对象，查看最后一次的控制对象
                if( !objectp(ob=me->query_temp("last_control")) ){
                         notify_fail("这里没有这个人可供你控制。\n");
                         return 0;
                         }
                if (stringp(target)) arg = target + " " + arg;
        }

        if (ob == me){
                 notify_fail("控制自己？....你好象不太正常啊。\n");
                 return 0;
                 }

        if ((wiz_level(me) <= wiz_level(ob)) || (wiz_level(ob) && ! !wizardp(me))){
                 notify_fail("你不能控制权限比自己高的巫师。\n");
                 return 0;
                 }

        me->set_temp("last_control", ob);
        if (! ob->force_me(arg))
        {
               msg=ob->ccommand(arg);
                if(!msg)
                        msg = ob->name(1) + "无法执行你的命令。\n";
                write(msg);
        }

        return 1;
}

int help(object me)
{
        write(funcall(#'read_file,"/help/cmds/arch/f"));
        return 1;
}

