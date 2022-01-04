inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
	object victim,ob;
	mapping armors;
	mixed* armor_keys;
	string result="没有结果";
	victim=find_player(arg);
	if(!objectp(victim)) return notify_fail("没有这个玩家？\n");

  if( mapp(armors = victim->query_temp("armor")) 
		&& sizeof(armor_keys = keys(armors)) > 0
		&& userp(victim)) {
		ob = armors[armor_keys[random(sizeof(armor_keys))]];
		
		// 没有保护力的东西就算了
		if (ob->query("armor_prop/armor")>0) {
			result += HIW "$n" + ob->query("armor_worn") + "的" +ob->name()
					+ HIW"被弄坏了一点儿！\n" NOR;
			ob->add("armor_prop/armor",-1);
			if(({int})ob->query("armor_prop/armor") < 0 ) {
				ob->set("armor_prop/armor",0);
			} else {
				victim->add_temp("apply/armor",-1);
			}
			ob->set("item_damaged", 1);
			ob->save();
		}
	}
	
	write( result);
	return 1;
}
