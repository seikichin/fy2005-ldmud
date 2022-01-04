// Silencer@fengyun workgroup	June.2005
// Modified so it won't update "possessed pet". It doesn't care about player/non-player pet though.

#include "/doc/help.h"

inherit F_CLEAN_UP;

int update_player(object me);

int main(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( getuid() );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("你要重新编译什麽档案？\n");

        if( (obj = present(file, environment(me))) && interactive(obj) )
                return update_player(obj);

        if( file == "me" )
                return update_player(me);
        else {
                file = resolve_path(me->query("cwd"), file);
                if( file[<2..<0]!=".c" ) file += ".c"; 
        }

        if( file_size(file)==-1 )
           	return notify_fail("没有这个档案。\n");
		if (wiz_level(me)<4)
			return notify_fail("你的权限不能重新编译文件。\n");
		
        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])|| 
                        	inv[i]->query("possessed")) {
                        	inv[i]->move(VOID_OB, 1);
                        } else {
                        	destruct(inv[i]);
			}
                }

                destruct(obj);
        }

        if (obj) return notify_fail("无法清除旧程式码。\n");

    	write("重新编译 " + file + "：");
        err = catch( call_other(file, "???") );
        if (err)
                printf( "发生错误：\n%s\n", err );
        else {
                write("成功！\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)%s updated %s\n", ctime(time()), me->query("name"), file));
        
        	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        {
                        	if( inv[i] && (userp(inv[i]) || inv[i]->query("possessed"))) 
					inv[i]->move(obj, 1);
                		
                	}
                }
        }
                
        return 1;
}

int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
      exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

        write("身体更新完毕。\n\n");
        obj->move(env);
        obj->write_prompt();

        return 1;
}

int update_player2(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

	obj->receive_fulling("sen",500);
	obj->receive_fulling("gin",500);	// Leave kee out to do a demo downstairs
        obj->set("startroom", AREA_FY"fqkhotel");
        write ("所有参数点分配完毕，人物创造完毕，欢迎进入风云世界。\n");
        obj->move(env);
        obj->set_temp("first_time_login",1);
        obj->set_temp("successful_login", 1);
        obj->write_prompt();

        return 1;
}

int help(object me)
{
   write(funcall(#'read_file,"/help/cmds/wiz/update"));
    return 1;
}
 
