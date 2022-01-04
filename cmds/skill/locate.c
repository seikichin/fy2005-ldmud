// by Tie@fy3 hehe
//	inherit F_CLEAN_UP;
#include <rtlimits.h>
inherit F_DBASE;
string locate_obj(object me,string strr);
string locate_quest(object me);
object find_env(object ob);
mapping *read_table(string file);
mapping *quests;
private mixed limited_eval(closure cl, int evals, varargs mixed* arg)
{
      return limited( (: apply(#'limited, $1, ({$2}), $3) :),
            ({ LIMIT_UNLIMITED }), cl, evals, arg);
}

#define MAX_DIS	7
#define MAX_ALT  2
#define MAX_DIR  8

mapping *read_table(string file) {
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = old_explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = old_explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = old_explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ m_allocate(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}
int main(object me, string str)
{
	string output = "";
        if(!str) return notify_fail("指令格式: locate 物品\n");
	if(me->query("sen") < 10) return notify_fail("你的心神不足以查寻位置。\n");
	if (uptime()<120 && !wizardp(me))
		return notify_fail("风云系统正在初始化，请等候两分钟。\n");
	me->receive_damage("sen",5);

	if (str == "quest")
	{
	      output =limited_eval((: locate_quest(me) :),0);
		if(output=="")
			return notify_fail("确定不了"+str+"的大概位置。\n");
		write(output);
		return 1;
	}
	
	if (str == "monster nian")
	{
		return notify_fail("活动NPC无法确认位置。\n");
		return 1;
	}
      
	output =limited_eval((: locate_obj(me,str) :),0);

//	if(output=="")
//		output = QUESTNPC_D->locate_obj(me,str);
	if(output=="" || !output)
		return notify_fail("确定不了"+str+"的大概位置。\n");
	write(output);
	return 1;
}

string locate_quest(object me)
{
	string *distance = ({
		"极近", "很近", "比较近", "不远",
		"不近", "比较远", "很远", "极远"
	});
	string *altitude =({
		"高处", "地方", "低处"
	});
	string *directions=({
		"周围","北方", "南方", "东方","西方",
		"东北方","西北方","东南方","西南方"
	});
	object ob, tmpobj,where, *ob_list;
	object item,room;
	string domain1,domain2;
	string output,dis,alt,dir;
	int i;
	int x,y,z,x0,y0,z0;
	int realdis;
	int tmp;
	string str="";

	if (!me->query("annie_questx/index"))
		return "王风没让你找东西啊。\n";

	item=me->query("annie_questx/mail");
	if (!item)
		return "这东西已经找不到了．．．\n";
	
	ob = find_env(item);
		room = environment(me);



				sscanf(file_name(room), "/d/%s/%~s", domain1);
				sscanf(file_name(ob), "/d/%s/%~s", domain2);
				x0= ({int})room->query("coor/x");
				y0= ({int})room->query("coor/y");
				z0= ({int})room->query("coor/z");

				if (domain1 == domain2) {
					x=({int})ob->query("coor/x")-x0;
					y=({int})ob->query("coor/y")-y0;
					z=({int})ob->query("coor/z")-z0;
				} else {
					x=ob->query("coor/x") / COOR_D->query_ratio(domain2)-
						x0 / COOR_D->query_ratio(domain1);
					y=ob->query("coor/y") /  COOR_D->query_ratio(domain2)-
						y0 /  COOR_D->query_ratio(domain1);
					z=ob->query("coor/z") /  COOR_D->query_ratio(domain2)-
						z0 / COOR_D->query_ratio(domain1);
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				}
				realdis=0;
				if(x<0)realdis-=x; else realdis+=x;
				if(y<0)realdis-=y; else realdis+=y;
				if(z<0)realdis-=z; else realdis+=z;
				tmp =realdis/50;
				if(tmp>MAX_DIS) tmp = MAX_DIS;
				dis=distance[tmp];
				if(z>0) alt=altitude[0];
				if(z<0) alt=altitude[2];
				if(z==0) alt=altitude[1];
				if(x==0&&y==0) dir=directions[0];
				if(x==0&&y>0) dir=directions[1];
				if(x==0&&y<0) dir=directions[2];
				if(x>0&&y==0) dir=directions[3];
				if(x<0&&y==0) dir=directions[4];
				if(x>0&&y>0) dir=directions[5];
				if(x<0&&y>0) dir=directions[6];
				if(x>0&&y<0) dir=directions[7];
				if(x<0&&y<0) dir=directions[8];
				output = "『"+item->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
				return output;

	return "";
}

string locate_obj(object me,string strr) {
	string *distance = ({
		"极近", "很近", "比较近", "不远",
		"不近", "比较远", "很远", "极远"
	});
	string *altitude =({
		"高处", "地方", "低处"
	});
	string *directions=({
		"周围","北方", "南方", "东方","西方",
		"东北方","西北方","东南方","西南方"
	});
	object ob, tmpobj,where, *ob_list;
	object item,room;
	string domain1,domain2;
	string output,dis,alt,dir;
	int i;
	int x,y,z,x0,y0,z0;
	int realdis;
	int tmp;
	string str="";
	seteuid(getuid());
	quests=read_table("/quest/dynamic_quest");
	
	for( i=0; i < sizeof(quests); i++)
	{
		if(!objectp(item= find_object(quests[i]["file_name"])))
			item = load_object(quests[i]["file_name"]);
		if (!item)	
			write("Please Report: Missing quest is "+ quests[i]["file_name"]+"\n");
		else
			if(item->query("id") == strr || item->query("name") == strr) 
				str = quests[i]["file_name"];
	}
	
	if(str != "") {
		room = environment(me);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
		ob=find_env(ob_list[i]);
		if(ob==0) continue;
			if(ob)			
			{	
		        	sscanf(file_name(room), "/d/%s/%~s", domain1);
		        	sscanf(file_name(ob), "/d/%s/%~s", domain2);
				x0= ({int})room->query("coor/x");
				y0= ({int})room->query("coor/y");
				z0= ({int})room->query("coor/z");
			/*	x=({int})ob->query("coor/x")-x0;
				y=({int})ob->query("coor/y")-y0;
				z=({int})ob->query("coor/z")-z0;
				if(domain1!=domain2)//如果在同一个区域就省了
				{
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				} */
				if (domain1 == domain2) {
					x=({int})ob->query("coor/x")-x0;
					y=({int})ob->query("coor/y")-y0;
					z=({int})ob->query("coor/z")-z0;
				} else {
					x=ob->query("coor/x") / COOR_D->query_ratio(domain2)-
						x0 / COOR_D->query_ratio(domain1);
					y=ob->query("coor/y") /  COOR_D->query_ratio(domain2)-
						y0 /  COOR_D->query_ratio(domain1);
					z=ob->query("coor/z") /  COOR_D->query_ratio(domain2)-
						z0 / COOR_D->query_ratio(domain1);
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				}

				realdis=0;
				if(x<0)realdis-=x; else realdis+=x;
				if(y<0)realdis-=y; else realdis+=y;
				if(z<0)realdis-=z; else realdis+=z;
				tmp =realdis/50;
				if(tmp>MAX_DIS) tmp = MAX_DIS;
				dis=distance[tmp];
				if(z>0) alt=altitude[0];
				if(z<0) alt=altitude[2];
				if(z==0) alt=altitude[1];
				if(x==0&&y==0) dir=directions[0];
				if(x==0&&y>0) dir=directions[1];
				if(x==0&&y<0) dir=directions[2];
				if(x>0&&y==0) dir=directions[3];
				if(x<0&&y==0) dir=directions[4];
				if(x>0&&y>0) dir=directions[5];
				if(x<0&&y>0) dir=directions[6];
				if(x>0&&y<0) dir=directions[7];
				if(x<0&&y<0) dir=directions[8];
				output = "『"+ob_list[i]->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
				return output;
			}
		else return "";
		
		}
	}
	else 
	if(wizardp(me) || me->query("class") == "official")
	{
		if (!wizardp(me) && me->query("combat_exp")<50000)
		{
			tell_object(this_player(),"确定他人的所在需要等级５。\n");
			return"";
		}		
		tmpobj = find_player(strr);
		if(!tmpobj) tmpobj = find_real_living(strr);
		if(!tmpobj) return "";

		if (!wizardp(me) 
			&& me->query("combat_exp")* 2 < tmpobj->query("combat_exp"))
		{	
			tell_object(me,"你的经验等级不足以确定此人的具体位置。\n");
			return"";
		}

		if (userp(tmpobj) && !wizardp(me))
		{
			tell_object(me, "你无法查寻玩家的具体位置。\n");
			return "";
		}	
		
			
			
		ob = find_env(tmpobj);
		room = environment(me);
		if(ob)
		{
			sscanf(file_name(room), "/d/%s/%~s", domain1);
	        	sscanf(file_name(ob), "/d/%s/%~s", domain2);
			x0= ({int})room->query("coor/x");
			y0= ({int})room->query("coor/y");
			z0= ({int})room->query("coor/z");
	/*		x=({int})ob->query("coor/x")-x0;
			y=({int})ob->query("coor/y")-y0;
			z=({int})ob->query("coor/z")-z0;
			if(domain1!=domain2)//如果在同一个区域就省了
			{
				x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
				y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
				z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
			}*/
			if (domain1 == domain2) {
				x=({int})ob->query("coor/x")-x0;
				y=({int})ob->query("coor/y")-y0;
				z=({int})ob->query("coor/z")-z0;
			} else {
				x=ob->query("coor/x") / COOR_D->query_ratio(domain2)-
					x0 / COOR_D->query_ratio(domain1);
				y=ob->query("coor/y") /  COOR_D->query_ratio(domain2)-
					y0 /  COOR_D->query_ratio(domain1);
				z=ob->query("coor/z") /  COOR_D->query_ratio(domain2)-
					z0 / COOR_D->query_ratio(domain1);
				x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
				y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
				z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
			}
			realdis=0;
			if(x<0)realdis-=x; else realdis+=x;
			if(y<0)realdis-=y; else realdis+=y;
			if(z<0)realdis-=z; else realdis+=z;
			tmp =realdis/50;
			if(tmp>MAX_DIS) tmp = MAX_DIS;
			dis=distance[tmp];
			if(z>0) alt=altitude[0];
			if(z<0) alt=altitude[2];
			if(z==0) alt=altitude[1];
			if(x==0&&y==0) dir=directions[0];
			if(x==0&&y>0) dir=directions[1];
			if(x==0&&y<0) dir=directions[2];
			if(x>0&&y==0) dir=directions[3];
			if(x<0&&y==0) dir=directions[4];
			if(x>0&&y>0) dir=directions[5];
			if(x<0&&y>0) dir=directions[6];
			if(x>0&&y<0) dir=directions[7];
			if(x<0&&y<0) dir=directions[8];
			
//	忍术的遁形之术使你不再被准确地locate。For wizards, well, you can always use "where"。			
			if (tmpobj->query_temp("ninjitsu/chameleon")==2)
				output = "『"+tmpobj->query("name")+"』似乎在"+dir+"。\n";
			else if (tmpobj->query_temp("ninjitsu/chameleon")==1)
				output = "『"+tmpobj->query("name")+"』似乎在"+dir+"的"+alt+"。\n";
			else
				output = "『"+tmpobj->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
					
			return output;
		}
		else return "";
	}
	else
 		return "你不是朝廷官员，不能locate。\n";

return "";
}



int help(object me)
{
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	locate <物品>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"这个指令是用来得知使命物品的大概位置，每次使用会消耗5点心神。\n"
"朝廷官员还可以用此指令查寻游戏人物的大概位置。\n"
"（注意，你只能查寻到不超过自身经验值两倍的非玩家人物）\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
""
	);
	return 1;
}

object find_env(object ob)
{
	while(ob)
	{
	if(ob->query("coor") ) return ob;
	else ob=environment(ob);	
	}
	return ob;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/




