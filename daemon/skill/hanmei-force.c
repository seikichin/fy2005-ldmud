#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","寒梅心法");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","huashan");
	
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, x, dmg;
	
	if ((x=me->query_temp("pfm/hs_mthy_shield")>0)) {
		message_vision(WHT"$N"NOR WHT"身畔寒星忽由微光遽变作厉芒，激射$n"NOR WHT"，竟是避无可避！\n"NOR, me, ob);
		COMBAT_D->report_status(ob);
		dmg = COMBAT_D->magic_modifier(me, ob, "kee", me->query_skill("tanzhi-shentong",1)); // 160 per hit
		ob->receive_damage("kee", dmg, me);
		if (me->query_temp("pfm/hs_mthy_shield")<2)
			me->delete_temp("pfm/hs_mthy_shield");
		else
			me->add_temp("pfm/hs_mthy_shield",-1);
	}
		
	if (damage <=0)	return 0;		
	if( me->query_temp("pfm/hs_yingyueliuhui")<=0
		|| me->query("class")!= "huashan"
		|| me->query_skill_mapped("iron-cloth")!= "spring-water")
		return 0;
	
	num = me->query_temp("pfm/hs_yingyueliuhui");
	
	if (!random(4)){
		me->add_temp("pfm/hs_yingyueliuhui",-1);
		data["msg"] = WHT"$N一招攻去，却如攻入波光幻影，失去了$n的行踪！\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/hs_yingyueliuhui") <= 0) {
			ANNIE_D->debuff(me, "hs_yylh");
		}	
	} 	
	return data;	
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
