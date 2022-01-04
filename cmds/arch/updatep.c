// updatep.c
#include <ansi.h>
#include <rtlimits.h>
inherit F_CLEAN_UP;
private mixed stat( string dir ){
  mixed file;
	file=transpose_array(({ get_dir(dir, 0x01|0x20)
                         , get_dir(dir, 0x02)
                         , get_dir(dir, 0x40) }));
return file;
}
int error;

int update_function(object me, string file);
private mixed limited_eval(closure cl, int evals, varargs mixed* arg)
{
    // Sprung ueber Unlimited machen, damit die verbrauchten
    // Evals nicht fuer den normalen Ablauf mitzaehlen.
    return limited( (: apply(#'limited, $1, ({$2}), $3) :),
            ({ LIMIT_UNLIMITED }), cl, evals, arg);
}

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    	string *files;
    	int i,total=0;
    	int size;
    	seteuid(getuid());
    	if(!arg || arg=="") { notify_fail("格式不对！\n");return 0;}
    
    	error = 0;
    	
    	write(HIW"正在梭巡"+arg+"文档夹．．．\n"NOR);
    	
    	files= get_dir(arg);
    	for(i=0; i<sizeof(files); i++) 
    	{
    	    size=sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c"){
        		if (files[i]=="updatep.c") continue;
        		total++;
				limited_eval((:update_function(me, arg+files[i]):),0);
			}	
        }   
        
        write(HIW"．．．"+arg+"文档夹编译完成。\n"
"　　　共梭巡到"+total+"个档案，其中"+error+"个编译失败。\n"NOR);	 	
    	return 1;
}

int update_function(object me, string file)
{
        int i;
        object obj, *inv;
        string err,tmp;

        seteuid( geteuid(me) );
        if (!file) file = me->query("cwf");
        if (!file){
               return notify_fail("你要重新编译什麽档案？\n");
                      }
               

		file = resolve_path(me->query("cwd"), file);
	
	  if( sscanf(file, "%s.c",tmp)!=1 ) file =tmp+".c"; 
        if( file_size(file)==-1 ){
               return notify_fail("没有这个档案。\n");
                 }

        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB ){
                                 notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
                                 return 0;
                                 }
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])) {
                        	inv[i]->move(VOID_OB, 1);
                        } else {
                        	destruct(inv[i]);
			}
                }

                destruct(obj);
        }

        if (obj) { notify_fail("无法清除旧程式码。\n");return 0;}

    	write("重新编译 " + file + "：");
        err = catch( call_other(file, "???") );
        if (err)
		{
			error++;
                printf( "发生错误：\n%s\n", err );
                log_file( "UPDATE_error", sprintf("(%s)%s updated error %s\n", ctime(time()), me->query("name"), file));
			}
        else {
              write("成功！\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)%s updated %s\n", ctime(time()), me->query("name"), file));
        
        	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        	if( inv[i] && userp(inv[i]) ) 
					inv[i]->move(obj, 1);
                }
        }
                
        return 1;
}

int help(object me)
{
     write(funcall(#'read_file,"/help/cmds/arch/updatep"));
    return 1;
}
