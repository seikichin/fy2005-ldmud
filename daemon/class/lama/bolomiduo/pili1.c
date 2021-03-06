// Silencer @ FY4 workgroup. Aug.2004
//	gin -40 DS

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	object *team, *team1;
	int i, skill, iron, num;
	mapping buff;

	if (me->query("class")!= "lama")
		return notify_fail("只有大昭弟子才能运用『霹雳心法』\n");
		
	skill = me->query_skill("bolomiduo",1);
	if (skill < 160)
		return notify_fail("『霹雳心法』需要160级婆萝蜜多心经。\n");
	
	iron = me->query_skill("jin-gang",1);
	if (iron < 180)
		return notify_fail("『霹雳心法』需要180级金刚不坏神功。\n");
		
	if (ANNIE_D->check_buff(me, "feat") || ANNIE_D->check_buff(me, "damageshield"))
		return notify_fail("你已经在使用类似的武功了。\n");
	
	if( ({int})me->query("force") < 200 )
		return notify_fail("『霹雳心法』需要200点的内力。\n");
	
	if (userp(me))	me->add("force", -200);
	me->start_busy(2);
	
	message_vision(HIW "$N"HIW"的衣服好似大海般的滚腾起来，翻跃、伏踞，又冲折、起落不己。\n"
"全身的骨节，竟如霹雳般“啪啪”地爆响起来！\n" NOR, me);
        
        team1 = me->query_team();
	
	skill = skill/4;
	
	if (!team1) {
		buff =
		([
			"caster":me,
			"who":	me,
			"type": "damageshield",
			"type2": "resistup",
			"att": "bless",
			"name": "婆萝蜜多心经·霹雳心法",
			"time": 180,
			"shield_desc":HIW"$n"HIW"一触$N"HIW"衣衫，忽然全身大震，如遭电击。\n"NOR,
			"shield_amount":skill,
			"shield_type":"gin",
			"buff1": "resistance/gin",
			"buff1_c": 10,	
			"buff_msg":"",
		//	"warn_msg":WHT"你的『霹雳心法』很快就要结束了。\n"NOR,
		//	"disa_msg":YEL"你的『霹雳心法』运行完毕！\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	}else {	
		team = filter(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (team[i]->query_temp("damage_shield")) continue;
			buff =
				([
					"caster":me,
					"who":	team[i],
					"type": "damageshield",
					"att": "bless",
					"name": "婆萝蜜多心经·霹雳心法",
					"time": 180,
					"shield_desc":HIW"$n"HIW"一触$N"HIW"衣衫，忽然全身大震，忽然如遭电击。\n"NOR,
					"shield_amount":skill,
					"shield_type":"gin",
					"buff_msg":"",
		//			"warn_msg":WHT"你的『霹雳心法』很快就要结束了。\n"NOR,
		//			"disa_msg":YEL"你的『霹雳心法』运行完毕！\n"NOR,
				]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL""+me->name()+"在你身上施加了『霹雳心法』\n"NOR);
		}
        }
        
	return 1;
}

