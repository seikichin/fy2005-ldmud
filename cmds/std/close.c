// close.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir;
	int i;

	if( !arg ) return notify_fail("你要关闭什麽？\n");

	doors = environment(me)->query_doors();
	if( mappingp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("你要关闭什麽？\n");
	
		if( environment(me)->close_door(dir) ) {
			message_vision("$N将" + doors[dir]["name"] + "关上。\n", me);
			return 1;
		}
	}

	return 0;
}

int help(object me)
{
        write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	 close <door> 或 <方向> 或 <容器>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
" \n"
"这个指令可以让你关上门或容器。\n"
"\n"
"相关指令: open\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
" \n"
);
    return 1;
}
