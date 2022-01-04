// A unified WHO, WHO -i
#include <ansi.h>

void create()
{
        seteuid(getuid());
}


string local_whos(string arg)
{
// arg can be -i id onnly, -n name only -l long 

	string str = "◎ " +"风云" + "\n";
	object *list;
	int ppl_cnt,j;
	list = sort_array(efun::users(),"sort_user",this_object());
	j = sizeof(list);
	ppl_cnt = 0;
	str += "—————————————————————————————————————\n";
	while( j--)
	{
	if( !environment(list[j]) ) continue;
	switch(arg) {
	case "-i" :
        str = sprintf("%s%-15s%s",
                str,
                capitalize(list[j]->query("id")),
                (ppl_cnt%5==4? "\n": "")
        );
        ppl_cnt++;
		break;
	case "-n" :
        str = sprintf("%s%-15s%s",
                str,
                list[j]->name(1),
                (ppl_cnt%5==4? "\n": "")
        );
        ppl_cnt++;
                break;
	case "-l" :
	str = sprintf("%s%s",
                str,
                list[j]->short(1)+"\n");
		break;
        case "-w" :
		if(wizardp(list[j]) ){
        str = sprintf("%s%s",
                str,
                list[j]->short(1)+"\n");
					}
                break;
	default :
        str = sprintf("%s%-15s%s",
                str,
                list[j]->name(1),
                (ppl_cnt%5==4? "\n": "")
        );
        ppl_cnt++;
		    }
	}	
  
        if(arg!="-l" && arg!="-w") str+="\n";
        str +="—————————————————————————————————————\n";
	str = sprintf("%s共有%s位人士正在游戏中。\n", str,
	chinese_number(sizeof(list)));
	return str;
}

int query_num()
{
	return sizeof(efun::users());
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;

        if( wizardp(ob2) && !wizardp(ob1) ) return 1;


	return (ob1->short(1)+" ">ob2->short(1)+ " ");
}