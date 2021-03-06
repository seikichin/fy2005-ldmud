#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","满江红心法");
	set("effective_level",130);
	set("difficulty",200);
	set("type","force");
	set("usage/force",1);
	set("skill_class","official");
	
}	


mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, i;
	object *huwei;
	
	if (damage <=0)	return 0;	
	if( me->query_temp("pfm/yue-bgjs")<=0)
		return 0;
	
	huwei = filter(all_inventory(environment(me)), (: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    num = sizeof(huwei);	
    if (num<= 0)	return 0;
    
    // Consider 4 huwei, it's like 4+ hits immune.
	for (i=0;i<num;i++){
		if (huwei[i]->query("kee")>0 && !huwei[i]->query_temp("is_unconcious") ) {
			data["msg"] = WHT""+huwei[i]->name()+ WHT"舍命挡在$n身前，"+ chinese_number(damage*3)+ "点鲜血飞溅！\n"NOR,
			data["damage"] = - damage;
			huwei[i]->receive_damage("kee",damage*3, ob);
//			COMBAT_D->report_status(huwei[i]);	
			return data;
		}
	}
	 	
	return 0;	
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
