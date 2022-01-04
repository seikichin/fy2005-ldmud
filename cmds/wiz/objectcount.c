

int main(object me, string arg1)
{
        int mark_loaded;
        int i,totalCount;
        int CountInEn=0;
        string dir,flag,arg;
        mixed *file;
        object *objectlist;
        
        if (!arg1)
        	return notify_fail("你要察看哪个文件？\n");
        	
        if (sscanf(arg1,"%s -%s",arg, flag)!=2)
        	return notify_fail("格式不正确，请察看使用说明。\n");
				        
        if (flag && flag != "destroy" && flag != "count")
        	return notify_fail("参数不正确，请参看使用说明。\n");
        	
        if (wiz_level(me)<5 && flag =="destroy")
        	return notify_fail("你的权限无法摧毁文件。\n");
        	        
        dir = resolve_path(me->query("cwd"), arg);

        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {
                if (file_size(dir) == -2) 
                        return notify_fail("dir is empty。\n");
                else 
                        return notify_fail("no such dir or file。\n");
        }

        i = sizeof(file);
        
        write("object info for " + dir + "\n");
        
        if (sizeof(file))
        {
                int obCount;
                string obFileFullPath,obFile;
                for(i=0; i < sizeof(file); i++)
                {
                        obFileFullPath = dir + file[i][0];
                        
                        if(sscanf(obFileFullPath,"%s.c",obFile) == 1 || sscanf(obFileFullPath,"%s.o",obFile))
                        {
                                objectlist = children(obFile);
                                obCount = sizeof(objectlist);
                                if(obCount > 0)
                                {
                                        printf("object base name %s:  %d \n",obFile,obCount);
                                        totalCount += obCount;
                                }
                        }
                                
                        //find_object(dir + file[i][0])) 
                }
                printf("Total object count : %d \n",totalCount);
                
        		 
                for(i=0;i<sizeof(objectlist);i++)
                {
                	if (flag == "destroy")
                		destruct(objectlist[i]);
                	else if(environment(objectlist[i]))
                	{
                		CountInEn++;
//                		printf("obj No. %d is in %O\n",i,environment(objectlist[i]));
//                		reset_eval_cost();
                		
                	}
                	
        		}
        		if (flag == "destroy")
                	printf("ALL CHILDREN OBJECTS destroyed\n");
                else
                	printf("Total object count in Env: %d \n",CountInEn);
        }
        else 
                write("    no file。\n");
        write("\n");    
        return 1;       
}


int help(object me)
{
write(funcall(#'read_file,"/help/cmds/wiz/objectcount"));
   return 1;
}
