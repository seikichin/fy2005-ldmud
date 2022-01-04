// updatepartner.c
// 辅助编译一个目录及其子目录下的.c文件
// ---- Silencer@FY4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;
int total, error;
int update_files(object me, string *files, string parent, int count);

int main(object me, string arg)

{
    	string arg1;
    	string *files;
    	int count;
    	total = 0;
    	error = 0;
    	    	
    	seteuid(getuid());
    	if(!arg || arg=="") { notify_fail("格式不对！\n");return 0;}
		if (me->query("id")!= "smaug"){
			 notify_fail("私人调试命令，仅在local使用。\n");return 0;}
		
		files =get_dir(arg);
    	update_files(me, files, arg, 3);
    	
    	write(HIR"\n\n编译终结，请察看出错信息。\n"NOR);
    	write(HIR" 成功 : "+ total + ";   失败" +error + "\n"NOR);
    	return 1;
}


int update_single_file(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file){
                 notify_fail("你要重新编译什麽档案？\n");
                 return 0;
                 }

        if( (obj = present(file, environment(me))) && interactive(obj) ) {
        	write("非正常编译。\n");
                return 1;
	}
	
        if( file == "me" ) {
        	write("非正常编译。\n");
                return 1;
	}
	else {
                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 
        }

        if( file_size(file)==-1 ){
                 notify_fail("没有这个档案。\n");
                 return 0;
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
        if (err) {
                printf("发生错误：\n%s\n", err );
        	error++;
        }	
        else {
                total++;
                write("编译成功！\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)%s updated %s\n", ctime(time()), me->query("name"), file));
               	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        	if( inv[i] && userp(inv[i]) ) 
					inv[i]->move(obj, 1);
                }
        }
                
        return 1;

}



int update_files(object me, string *files, string parent, int count){
	
	int i, size;
	string *files2;
	
	for(i=0; i<sizeof(files); i++) {
		if (parent + files[i] == "/cmds/adm/updatepartner3.c") continue;
		size=sizeof(files[i]);
		if(files[i][(size-2)..size]==".c") {
	  	       	update_single_file(me, parent+files[i]);
//	  	       	me->ccommand(sprintf("update %s%s",parent,files[i]));
	        } else if (pointerp(get_dir(files[i]))) {
			if (count>1) {
				files2 = get_dir(parent+files[i]+"/");
				update_files(me, files2, parent+files[i]+"/",count-1);	
			}
		}
	}
	return 1;
}


int help(object me)
{
  write(funcall(#'read_file,"/help/cmds/adm/updatepartner"));
    return 1;
}
 
