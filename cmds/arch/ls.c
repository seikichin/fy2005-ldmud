// ls.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col;
	string dir;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	
	file=transpose_array(({ get_dir(dir, 0x01|0x20)
                         , get_dir(dir, 0x02)
                         , get_dir(dir, 0x04) }));
	

	if( !sizeof(file) )
	{if (file_size(dir) == -2) { notify_fail("目录是空的。\n");return 0;}
		else{
		 return notify_fail("没有这个目录。\n");
                  }
	}

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
              		
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
	}
	write("目录：" + dir + "\n");
	col = 70 / (w+6);
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
			printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
				file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
				((i+1)%col)?"  ":"\n");
	else write("    没有任何档案。\n");
	write("\n");
	
	return 1;	
}

int help(object me)
{
	write(funcall(#'read_file,"/help/cmds/arch/ls"));
	return 1;
}
