inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int time;
        if(!arg || sscanf(arg,"%d",time)!=1)
        	return notify_fail("USAGE:convtime time.\n");
        write(sprintf("您输入的为：%d，对应时间为：%s\n",time,ctime(time)));
        return 1;
}

int help(object me)
{

write(funcall(#'read_file,"/help/cmds/wiz/convtime"));
    return 1;
}
