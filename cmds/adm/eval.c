#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	
	    /* clean up first */
    if (file_size("/tmp_eval_file.c") != -1)
	rm ("/tmp_eval_file.c");
    if (find_object("/tmp_eval_file"))
	destruct(find_object("/tmp_eval_file"));

    write_file("/tmp_eval_file.c","mixed eval() { "+arg+"; }\n");
    printf("\nResult = %O\n", "/tmp_eval_file"->eval());
    return 1;

}
