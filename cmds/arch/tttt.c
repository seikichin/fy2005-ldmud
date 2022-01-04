           // Annie. 2005 
// Dancing_Faery@HOTMAIL.COM


#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
string* files;
string *read_table(string file);
int update_function(object me, string file);
int analysis(string a);
int deep_analysis(string a);

int b=0,c=0,d=0,e=0;

int main(object me, string arg)
{
        int i,a;

        seteuid(getuid());
        files=read_table("change.txt");
        b=0;c=0;d=0;e=0;
        write("\n");
        for (i=0; i<sizeof(files); i++) {
        	if (i%100 == 0) 
        	analysis(files[i]);
		}
		
       	write(HIY+(b+c)+HIC"个档案被发现，"HIY+b+HIC"个档案处理成功，"HIY+c+HIC"个档案处理失败。\n"NOR);
       	write(HIC"有"+HIY+e+HIC"个档案未通过编译。\n"NOR);

       	write("Ok.\n");
        return 1;
}


string *read_table(string file)
{
        string *line, *field, *format;
        string *data;
        int i, rn, fn;
        data = ({});
                if (read_file(file))
                {
                        line = old_explode(read_file(file), "\n");
                        for( i=0; i<sizeof(line); i++)
                        {
                                        if( line[i]=="" || line[i][0]=='#' ) continue;
                                        data+=({line[i]});
                        }
                }
        return data;

}

int analysis(string a)
{
        string* dirs;
        string tmp;
        int i;
        string ext = ".c";

        if (a[0] == '!')
        {
                ext="";
                a=a[1..];
        }

        if (a[0] == '@')
        {
                //
                return deep_analysis(a[1..]);
        }

        if( file_size(a+ext) < 0 )
        {
                write(HIG"没有"+a+"这个档案。\n"NOR);
                log_file("tttt","没有"+a+"这个档案。\n"); 
                c++;
                return 0;
        }

        dirs = old_explode(a, "/");
        mkdir("bunny");
        tmp="bunny/";
        for (i=0;i<sizeof(dirs)-1;i++)
        {
                tmp += dirs[i];
                mkdir(tmp);
                tmp += "/";
        }

        if (update_function(this_player(),a+ext))
        {
                d++;
        }
        else
        {
                e++;
                write(HIR"档案"+a+"编译失败。\n"NOR);
                log_file("tttt","档案"+a+"编译失败。\n"); 
        }
        
        if (copy_file(a+ext,"/bunny"+a+ext))
                write(HIW"档案"+a+"已成功处理。\n"NOR);
        b++;
        return 1;
        
}






int update_function(object me, string file)
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

                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 

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

        if (obj) { notify_fail("无法清除旧程式码。\n"); return 0;}

//      write("重新编译 " + file + "：");
        err = catch( call_other(file, "???") );
        if (err)
                {
        		write(HIR"在编译 " + file + "时");
                	printf( "发生错误：\n%s\n"NOR, err );
           		log_file("tttt","编译"+file+"失败，发生错误。\n"); 
                        }
        else {
//                write("成功！\n");
                log_file( "UPDATE_LOG", sprintf("(%s)%s updated %s\n", ctime(time()), me->query("name"), file));
        
                if( (i=sizeof(inv)) && (obj = find_object(file))) {
                        while(i--)
                                if( inv[i] && userp(inv[i]) ) 
                                        inv[i]->move(obj, 1);
                }
        }
                
        return 1;
}


int deep_analysis(string a)
{
        // get file list first;
        mixed *file;
        int i;
        file = get_dir(a, -1);
        if( !sizeof(file) )
        {
                if (file_size(a) == -2) {
                        write(HIG+a+"档案夹为空。\n"NOR);
                		log_file("tttt",a+"档案夹为空。\n"); 
                }
                else	{
                        write(HIG+a+"档案夹不存在。\n"NOR);
                        log_file("tttt",a+"档案夹不存在。\n"); 
                }        
                c++;
                return 0;
        }

        i = sizeof(file);
        while(i--) 
        {
                if (file[i][1]==-2) 
                {
                        deep_analysis(a+file[i][0]+"/");
                        continue;
                }
                analysis("!"+a+file[i][0]);
        }
        write(HIB+a+"档案夹处理完毕。\n"NOR);
        return 0;
}


int help(object me)
{
   write(funcall(#'read_file,"/help/cmds/arch/tttt"));
   return 1;
}

/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/

