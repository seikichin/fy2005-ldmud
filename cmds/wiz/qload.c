// qload.c

inherit F_CLEAN_UP;

int main()
{
    write(query_load_average() + "\n");
    return 1;
}

int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/qload"));
    return 1;
}
