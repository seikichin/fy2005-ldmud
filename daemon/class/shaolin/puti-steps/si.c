// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    int skill, num, i, duration,add;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
    if (userp(me))
    if (me->query("family/master_id")!="master yue" 
       	|| me->query("class")!="official")
       	return notify_fail("只有岳飞的弟子才能使用『四车兜底阵』。\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 170 || me->query_skill("leadership",1)< 170)
		return notify_fail("『四车兜底阵』需要170级兵法和170级用人之技。\n");        		
	       
	  add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;
	       
    duration = me->query("timer/pfm/yue_array")-time() + 10 - add;
	if (duration>0)
        	return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        
	if (me->query_temp("guard_count")<2)
        	return notify_fail("你的护卫太少，列不出阵法耶。\n");
        	
	msg = BGRN + HIY"$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"四车兜底之阵！\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	// 250/3 = 83
		
	if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
	// Well: SHiwei = shiwei + friend + myself:)
    shiwei = filter(all_inventory(environment(me)),
       		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    
    num = sizeof(shiwei);	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"兵法·四车兜底阵",
				"buff1":"apply/parry",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",
				"disa_type":1,			
			]);
		ANNIE_D->buffup(buff);		
    }
    return 1;
}
