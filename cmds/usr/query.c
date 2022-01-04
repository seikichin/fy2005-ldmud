// query.c

#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg) {
	
	mixed result,result1,result2;
	string name;
	 if (!arg)
		return notify_fail("[0;1;36m指令格式 : query 查询内容[0m\n");
	if( time()-me->query_temp("last_query") < 20 )
                return notify_fail("系统气喘嘘地叹道：慢慢来 ....\n");
      me->set_temp("last_query", time());	
       result=QUERY_D->db_query(arg);
       if(arrayp(result)){
       result1=json_parse(result[4]);
       result2=result[0];
       name=result1["env"]["0"]->name();
       if(name) result2=result2+" -> "+name;
       write("[0;1;37m你查询的物品所在位置为：[0m\n"+result2+"\n");
       }
       
       if(intp(result))  write("未查询到任何结果。\n");
	return 1;
}





int help(object me) {
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 		ｑｕｅｒｙ　查询内容[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"\n"
"这个指令可以显示出查询任务物品的位置。\n"
"\n"
"[0;1;37m────────────────────────────────[0m\n"
"\n"
"");
	return 1;
}
