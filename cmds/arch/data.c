//Copyright (C) 1996-2000 Apstone, Inc. All Rights Reserved.

// File : /cmds/wiz/data.c
// Last Modified : Mon Nov  9 22:49:16 1998
inherit F_DBASE;
#include <dbase.h>
#include <ansi.h>

int help(object me);
private int sort_keys(string one, string two);

int main(object me, string arg)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    object ob, ob1;
    string text,*tmp, id, spec;
    int loop;

    //Security check??
    seteuid(geteuid(me));
    
    if (arg)
    {
        sscanf (arg, "%s %s", spec, arg);
        if (arg == "-t" || arg == "-d")
        {
            spec = arg;
            arg = 0;
        }
        if (spec && spec != "-d" && spec != "-t")
        {
            arg = spec + " " + arg;
            spec = 0;
        }
    }
    if(!arg || arg == "")  ob=me;
    else if (sscanf (arg, "%s in %s", arg, id) == 2)
    {
        ob1=present(id, environment(me));
        if (!ob1) ob1 = present(id, me);
        if (!ob1) { notify_fail ("Data：本地无此生物: "+id+"\n");return 0;}
        if (!ob=present(arg, ob1)){
             notify_fail ("Data：该生物身上无此物件: "+arg+"\n");
             return 0;
             }
    }
    else if (arg == "here") ob = environment(me);
    else
    {
        arg = lower_case(arg);
        
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_real_living(arg);
        if (!ob) ob = present(arg, me);
        if(!ob) { notify_fail("Data：无法找到此物件: "+arg+"。\n"); return 0;}
    }
    
    list = ({mapping})ob->query_entire_dbase();
    tlist = ({mapping})ob->query_entire_temp_dbase();
    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist))){
        notify_fail("Data：此物件并没有任何的资料。\n");return 0;}
    
    if (sizeof(list))
    {
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
    }
    
    if (sizeof(tlist))
    {
        tlist2 = keys(tlist);
        tlist2 = sort_array(tlist2, "sort_keys", this_object());
    }
    
    
    if(!klist || !sizeof(klist)){
         notify_fail("Data：此物件并没有储存任何资料。\n");
         return 0;
         }

    if (!spec || spec == "-d")
    {
        text = HIW"物件：" + base_name(ob) + ".c"NOR"\n";
        
        for(loop=0; loop<sizeof(klist); loop++)
        {
            if(strlen(klist[loop]) > 7)  text += klist[loop] + "\t: ";
            else text += klist[loop] + "\t\t: ";
            
            text +=sprintf("%O \n",list[ klist[loop] ]);
        }
        text += "\n"HIW"总共有 " + sizeof(klist) + " 个储存的资料。"NOR"\n\n";
    }
    else text = "";
    
    if (!spec || spec == "-t")
    {
        text += HIW"暂存资料："NOR"\n\n";
 
        for(loop=0; loop<sizeof(tlist2); loop++)
        {
            if(strlen(tlist2[loop]) > 7)  text += tlist2[loop] + "\t: ";
            else text += tlist2[loop] + "\t\t: ";
            text +=sprintf("%O \n",tlist[ tlist2[loop] ]); 
        }
        
        text += "\n"HIW"总共有 " + sizeof(tlist2) + " 个暂存的资料。"NOR"\n\n";
    }
    
    me->start_more("", text, 0);
    return 1;
}
 
//  This function is used to sort the key array. 
private int sort_keys(string one, string two)
{
    return one>two;
}

int help(object me)
{
  write(funcall(#'read_file,"/help/cmds/arch/data"));
  return 1;
}
 
