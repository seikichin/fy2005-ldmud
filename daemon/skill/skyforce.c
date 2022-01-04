// skyforce

#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","碧空心法");
	set("type","force");
	set("effective_level",120);
	set("difficulty",200);
	set("usage/force",1);
	set("no_refund",({"henglian"}));
	set("skill_class","fugui");
	
}	

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	
	if (damage <=0)	return 0;	
	if( (me->query_temp("pfm/fg_erchuan")<=0 && me->query_temp("pfm/fg_sanchuan")<=0)
		|| me->query("class")!= "fugui"
		|| me->query_skill_mapped("iron-cloth")!= "henglian")
		return 0;
	
	if (me->query_temp("pfm/fg_erchuan")){
		me->add_temp("pfm/fg_erchuan",-1);
		data["msg"] = BBLU + WHT"$n的二串炮神功消去了$N的攻击！\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/fg_erchuan") <= 0) {
			ANNIE_D->debuff(me,"stoneskin");
		}	
	} 
	/*
	else
	{
		me->add_temp("pfm/fg_sanchuan",-1);
		data["msg"] = BBLU + WHT"$n的三串炸山轰神功消去了$N的攻击！\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/fg_sanchuan") <= 0) {
			ANNIE_D->remove_buffup( me, me->query_temp("buff_type/ironup"));
		}
	}*/
	return data;	
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
