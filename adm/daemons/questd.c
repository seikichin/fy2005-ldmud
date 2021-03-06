// questd.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
inherit F_ANNIE;
#include <ansi.h>


string wait_period(int timep);
int basic_quest_reward(int exp); 
int special_reward(object me, string qname);
void give_reward(object who,object accomplisher, mapping quest);
void log_quest(object me, object owner, mapping quest, int reward_exp, int used_time, int base);
int holiday_bonus=900;   	// 05/20/2008 fixed to x2 reward  注：额外的任务奖励。 
int chance = 20;
int level_chance = 80;

void create() {
    seteuid(ROOT_UID);
}


int query_holiday(){
	return holiday_bonus;	 
}

int set_holiday(int bonus){
	holiday_bonus = bonus;
	return holiday_bonus;
}

//	此函数检查Quest物品
//  The difference between "寻" and "杀" is
//  "杀" checks and gives credit to each teammate, "寻" searches for one then ends loop.
int accept_quest_object(object who, mixed ob, object me)
{
    int /*val,delay,*/ i/*, gr*/;
    string name; 
    object* mem;
    mapping quest;

	if (objectp(ob))
    if(ob->is_character()) {
		return 0;
    }

	if (objectp(ob)) name = ob->query("name");
	else if (stringp(ob))	name = ob;
	else	return 0;
		
    mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
    for(i=0; i<sizeof(mem); i++) {
	if (mem[i]) {
	    if(mapp(quest = mem[i]->query("quest")) 
	      && name == quest["quest"]
	      && ({string})(quest["quest_type"]) == "寻"
	      && (time() - mem[i]->query("quest_time") <= 900)) {

		give_reward(mem[i], who, quest);
		return 1;
	    }
	}
    }

    return 0;
}

//	发布Quest。

int give_quest(object who, mapping me)
{
    mapping quest,qmirror;
    mixed qex;
    int i/*, num*/, combatexp, max_exp, num_file, n1/*, n2*/, time;
    string tag = "_default";
    string qstr;
    object* mem;

    //	以防万一    
    if(who->is_ghost() || who->is_zombie()) {
	tell_object(who,"鬼魂不可要任务，请立即报告巫师，否则以利用BUG处理。\n");	
	 return notify_fail("\n");
    }

    //	现有的Quest还没有完成	
    time = who->query("quest/duration")>1 ? who->query("quest/duration") : 900; 
    if(qex =  who->query("quest") && (time() - who->query("quest_time") < time)) {
		return 0;
    }

    //	Cancel后的下一个时间还没到。	
    if((who->query("next_time")) > time()) {
	return 0;
    }

    max_exp = 0;
    combatexp =0;

    //	找出一个team里经验最高的人员
    mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
    i = sizeof (mem);
    while (i--)	{
	if (mem[i]) {
	    max_exp = mem[i]->query("combat_exp");
	    if (max_exp > 15000000) max_exp = 15000000;
	    combatexp = (max_exp>combatexp) ? max_exp : combatexp;
	}
    }


    //	选择哪个quest文件，注意前两个有可能选空
    num_file = combatexp / 1000;

    // 如果5分钟内连续cancel两次，50%可能下一个会是qlist_repeat
    if (who->query("marks/quest_cancel")>=2)
		n1 = 2;
    else if (who->query("marks/quest_cancel")>=1)
		n1 = 10;
    else
		n1 = 15;

    if(!random(n1))	{ 	
		tag = "_repeat";
		if (sizeof(mem)>1) 
	    	quest = QUEST_D(tag)->query_quest(combatexp/1000);
		else {
			quest = QUEST_D(tag+"_solo")->query_quest(combatexp/1000);
    	}
    }

    // DEBUG LINE   
   if (wizardp(who)) {
    	if (who->query("wiz_quest")=="repeat") 
    	{
    		tag = "_repeat";
    	   	quest = QUEST_D(tag)->query_quest(combatexp/1000);
    	} else if (who->query("wiz_quest")=="special") {
    		tag = "_special";
    	   	quest = QUEST_D(tag)->query_quest(combatexp/1000);
    	}  		
	}
	// DEBUG LINE END
	
    if (!sizeof(quest) || !quest) {
	if (!random(30)) {
	    tag = "_special";
	    if (sizeof(mem)>1)
	    	quest = QUEST_D(tag)->query_quest(combatexp/1000);
		else
			quest = QUEST_D(tag+"_solo")->query_quest(combatexp/1000);
	} 
    } else
    {
	// 如果 qlist_repeat 为真，delete repeat cancel mark.
		who->delete_temp("timer/quest_cancel");
		who->delete("marks/quest_cancel");
    }	

    //	CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",quest) );	

    if (!sizeof(quest) || !quest) {
		if( num_file < 100) 		tag="_small";		
		else if( num_file <= 1000) 	tag="_middle";
		else if (num_file <= 5000) 	tag="_large";
		else	tag="_super"; 
		
		quest = QUEST_D(tag)->query_quest(combatexp/1000);	
    }

    if (tag == "_special" || tag == "_repeat") {
		qmirror = mapping_copy(quest);// nip pointer bug.
		who->set("quest",qmirror);
		who->set("quest_time", time());
		who->add_temp("quest_number", 1);	
		qstr = quest["short"];						
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O ?? %O: %s", quest, qmirror, qstr));
    } else 
    {
		who->set("quest", quest);
		who->set("quest_time", time());
		who->add_temp("quest_number", 1);
		if (quest["quest_location"])
	    	qstr = HIW"到"+quest["quest_location"];
		else qstr="";

		if(quest["quest_type"] == "寻") {
	    	qstr += HIW"找回『"NOR + quest["quest"] + HIW"』给" 
	    	+ me["employer"] + HIW"。"NOR;
		} else if(quest["quest_type"] == "杀") {
	    	qstr += HIW"替" + me["employer"] + HIW"杀了『"NOR
	    	+ quest["quest"] + HIW"』。"NOR;
		}
    }

  if(who->query("env/maze") || who->query("chuili_unfinished")) { 
		tag = "_repeat";
		quest = ([
			"quest":	"探访垂笠老僧",
			"long":		"天机老人说：听闻最近有神秘组织频繁活动，你不妨去找城隍庙的和尚打听打听。",
			"short":	"去城隍庙找垂笠老僧打听神秘组织的情形",
			"owner":	"monk",		
			"location":	"城隍庙",		
			"duration":		1800,			
			"cancel": -1,	// CC +200% 
			"difficulty":	400,			
			"exp_l":		6000,						
			"exp_h":		10000,					
			"quest_type":	"special",		
		]),
		qmirror = mapping_copy(quest);// nip pointer bug.
		who->set("quest",qmirror);
		who->set("quest_time", time());
		who->add_temp("quest_number", 1);
		who->set("chuili_unfinished",1);	// 这个Mark只有在做完后才会消失，如果你不做，所有“寻”都会变成垂笠	
		qstr = quest["short"];						
	}



    //	公布Quest的内容：
    i = sizeof(mem);
    while (i--) {
	if (objectp(mem[i])) {
	    if (mem[i] == who) {
		if (tag == "_special" || tag=="_repeat")
		    tell_object(who, CYN + quest["long"] + "\n"NOR);
		else
		    tell_object(who, WHT + me["name"] + WHT"说道：请" + qstr + NOR"\n");
	    }
	    else 
		tell_object(mem[i], WHT + "队友 "+ who->name() + WHT" 现在的任务是: " + qstr + NOR"\n");

	}
    }

	CHANNEL_D->do_sys_channel("qst", sprintf("%s让%s(%s)%s\n", me["name"], HIW + who->name(), HIW + who->query("id"),HIW + qstr));

    return 1;
}


/*  Quest 奖励方式，只跟个人有关，不存在总体奖励的概念
		base = 受奖励者对应等级的基本Ｑｕｅｓｔ奖励 *75% (+ full_team 就是100%)
		bonus1 = Quest 难度，x1--x2
			(1)	比较难杀+5, 
			(2)	比较远+5, (包括物品) After 5M, this is no longer the case.
			(3)	肯定有生命危险+10-15, 
		bonus2 = Team	+5% per person to 25% top

	4.0 system base参考:
		0-10k, 		20 - 23
		10-800k, 	32 - 116
		880k-2.2M: 	116 - 233
		2.2M+		131+ random(91) --- 260

*/


void give_reward(object who, object accomplisher, mapping quest) 
{
	int team_size, i, level, base, d_bonus, team_bonus, combat_exp, silver, money, q_bonus, half;
//	int h_bonus;
	string reward_msg;
	object ob;
	object* mem;

	mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
	team_size = sizeof(mem);


	// special quest的exp_bonus按照拿Ｑｕｅｓｔ的那个人经验值计算
	if( quest["exp_bonus"] != 0 ) {
		q_bonus = quest["exp_bonus"];
	} else {
		q_bonus = who->query("combat_exp")/1000;
	}

	// reward money
	if( q_bonus > 3000 ) {
		money = 20+random(30);
	}else if( q_bonus > 1000 ) {
		money = 15+random(25);
	}else if( q_bonus > 100 ) {
		money = 10+random(20);
	}else {
		money = 5+random(10);
	}

	if( team_size ) {
		for( i = 0; i < team_size; i++ ) {
			// 注意，这里用的是F_LEVEL, 直接 query("level")得到的是曾经达到的最高lvl
			level = F_LEVEL->get_level(mem[i]->query("combat_exp"));
			base = REWARD_D->quest_reward(level);

// DEBUG LINE
#ifdef NONENCRYPTED_WRITE
	if( who->query("wiz_qreward") ) {
		base = base*who->query("wiz_qreward");
	}
#endif
// DEBUG LINE END
			if( quest["difficulty"] ) {
				d_bonus = quest["difficulty"];
			}
			team_bonus = (team_size-1)*5;
			// 最终奖励经验值。 REWARD CAPPED at 10M, 多余的进入ability或者只用来增加pot
			combat_exp = base*(100+d_bonus+team_bonus)/100/team_size;

			// Holiday rewards, 50=*0.5, 100 = *2, 200= *3 
			combat_exp = combat_exp*(100+query_holiday())/100;

			half = 1;
			if( mem[i]->query("death/half_quest") < 0 ) { // 此人有死亡损失
				// lv 50级以下，死亡超过24小时，肯定不能revive, 也没有Penalty
				if( level < 50 && mem[i]->query("death/time") + 86400 < time() ) {
					mem[i]->delete("death/half_quest");
					mem[i]->delete("death/exp_lost");
					mem[i]->set("death/revived", 1);
					tell_object(mem[i],"恭喜，你的死亡损失在２４小时后自动消失了！\n");
				} else {
					half = 2;
					mem[i]->add("death/half_quest",combat_exp/half);
				}
			}
			combat_exp = combat_exp/half;

			if( mem[i]->query("env/ability" ) 
				&& F_LEVEL->get_level(mem[i]->query("combat_exp"))>=80
				&& mem[i]->query("saved_quest")/60/100 < mem[i]->query("learned_ability")+6 ) {
				mem[i]->add("saved_quest", 60/team_size/half);
				if( query_holiday() )
					mem[i]->add("saved_quest", 60/team_size/half*query_holiday()/100);
			} else {
				if( mem[i]->query("combat_exp") >= 10000000 ) {
					mem[i]->add("extra_exp", combat_exp);
				}
				if( mem[i]->query("combat_exp") < 10000000 ) {
					mem[i]->add("combat_exp", combat_exp);
				}
				if( mem[i]->query("combat_exp") >= 10000000 ) {
					mem[i]->set("combat_exp",10000000);
				}
			}
			silver = money*(100+d_bonus+team_bonus)/100/team_size;
			silver = silver/half;

			// Holiday rewards, 50=*0.5, 100=*2, 200=*3
			silver = silver*(100+query_holiday())/100;
			// low level 25% extra silver bonus
			if( level < 50 ) {
				silver = silver*150/100;
			}

			// 直接入帐．
			mem[i]->add("deposit", silver*100);

			if( mem[i] != accomplisher) {
				if( mem[i] == who ) {
					reward_msg =YEL"你的任务被"+accomplisher->name()+"完成，你的经验值提高了" + "，奖励" + chinese_number(silver) + "两银子。\n\n" + NOR;
				} else {
					reward_msg =YEL+ who->name()+"的任务被"+accomplisher->name()+"完成，你的经验值提高了" + "，奖励" + chinese_number(silver) + "两银子。\n\n" + NOR;
				}
			} else {
				reward_msg = (accomplisher==who) ? WHT : WHT+"队友 "+who->name()+" 的";
				reward_msg +="任务被你完成，你的经验值提高了，奖励" +chinese_number(silver) + "两银子。\n" + NOR;
				if (random(100)>85)  //add by ldb 增加额外奖励，为了平衡队伍中经验少的ID。否则永远追不上来。
				{
                 ob=clone_object("/obj/wiz_toy/baoxiang1");
                 ob->move(this_player());
          		 tell_object(mem[i],HIY"由于你的勤恳努力，特奖励任务宝箱一个！\n");
				}
			}
			tell_object(mem[i],reward_msg);
			if( half == 2 ) {
				if( mem[i]->query("death/half_quest") < 0 ) {
	//				tell_object(mem[i],"（由于你最近的死亡，该任务奖励降为５０％）\n");
	//				tell_object(mem[i],"（按这样的速度，大约还需要" + (-mem[i]->query("death/half_quest")/combat_exp)+ "个任务后就没有惩罚了）\n");
				} else {
					mem[i]->delete("death");
					tell_object(mem[i],HIW"（恭喜，你的死亡损失已经全部消除了！）\n");
				}
			}
		}
	}

	who->set("quest", 0); // Quest清零
	if( who->query("cont_quest") < 20 ) {
		who->add("cont_quest",1);
	}
	accomplisher->add("FINISH_QUEST", 1);
	return;
}

string wait_period(int timep) {
    int t, d, h, m, s;
    string delay = "";

    t = timep;
    s = t % 60;             t /= 60;
    m = t % 60;             t /= 60;
    h = t % 24;             t /= 24;
    d = t;

    if(d) {
	delay += chinese_number(d) + "天";
    }
    if(h) {
	delay += chinese_number(h) + "小时";
    }
    if(m) {
	delay += chinese_number(m) + "分";
    }
    if(s) {
	delay += chinese_number(s) + "秒";
    }
    return delay;
}

//	送花的奖励
int flower_delivery_reward(object me, object who,object flower) {
    mapping delivery;
    int /*exp,pot,*/success_time,amount;
    object coin;

    if (!mapp(delivery = flower->query("delivery"))) return 0;
    if (base_name(who) != delivery["receiver"]) return 0;
    if (flower->query("delivery_time") != me->query("delivery_time")) return 0;

    success_time = ({int})me->query("marks/delivery_success");
    me ->set("marks/delivery_success",success_time+1);

    if (me->query("quest/quest")== "送花") 
	amount = 10;
    else
	amount = 1;

    coin = clone_object("/obj/money/silver");
    coin->set_amount(random(amount) + amount);

    switch (random(3))
    {
	    case 0:
		message_vision("$N兴奋地惊叫一声：“这是他送来的么？ ”\n",who);
		break;
	    case 1:
		message_vision("$N甜甜地对$n一笑说，多谢多谢。\n",who,me);
		break;
	    case 2:
		message_vision("$N满面春风，笑意盈盈，拍了拍$n道：“这是给你的，辛苦你了”。\n",who,me );	
		break;
    }

/*  if (coin)
    {
		coin->move(me);
		tell_object(me,who->name()+"递给你"+chinese_number(amount)+"两银子。\n");
    }*/

    if (me->query("quest/quest")== "送花") {
			special_reward(me,"送花");
    }    
    me->delete("delivery");
    me->delete("delivery_time");

    /*
    if(!undefinedp(quest["fin_func"])) {
	    call_other(this_object(),quest["fin_func"],me,who,quest_item);
    }*/
    if(flower) {
		destruct(flower);
    }
    return 1;
}

//	纪录一些极高的奖励值
void log_quest(object me, object owner, mapping quest, int reward_exp, int used_time, int base) 
{
    if (reward_exp <1000) return;

    log_file("QUEST_REWARD",
      sprintf("%s(%s) 完成了 %s(%s) 的任务 ：  %s %s 难度 %d 时间 %s\n奖励经验：%d used_time: %d  base: %d\n",
	me->name(1), geteuid(me), owner->name(1), geteuid(owner), quest["quest_type"], quest["quest"], quest["difficulty"], ctime(time()), 
	reward_exp, used_time, base));

}

//	Verify if you or team member has the qname quest	
int verify_quest(object me, string qname){

    mapping quest;
    object *mem;
    int i;

    mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
    for(i=0; i<sizeof(mem); i++) {
	if (objectp(mem[i])) {
	    if(mapp(quest = mem[i]->query("quest")) 
	      && mem[i]->query("quest/quest") == qname)
		return 1;
	}
    } 
    return 0;
}	

//	should be included in the one above.. but well, too late	
mapping return_quest(object me, string qname){

    mapping quest;
    object *mem;
    int i;

    mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
    for(i=0; i<sizeof(mem); i++) {
	if (objectp(mem[i])) {
	    if(mapp(quest = mem[i]->query("quest")) 
	      && mem[i]->query("quest/quest") == qname)
		return quest;
	}
    } 
    return 0;
}	

/*	此函数由Special Quest调用
	There are two kinds of Special Quest in FY2005
	Rewards will always be shared among teammates.
	(1) Those only can be finished by Quest_owner
		Example: 大部分到此一游的,对诗解密的
		用法：在Ｑｕｅｓｔ结束时call special_reward(me, quest_name)，
			在speical_reward里对合法性进行检查并give_reward(me, me, quest)奖励。

	(2) Those can be finished by any of team members
		If two or more teammates have same quests, only one can be finished at a time.
		It should be the achiever first, then pick one from the group
		Example: 杀三个一穷二白．
		用法：在Ｑｕｅｓｔ结束时，For best flexibility,
			自己决定accomplisher && who's_quest"_is_done.
			而后直接CALL give_reward(quest_owner, accomplisher, quest)

*/



int special_reward(object me, string qname) {

    mapping quest;
//  int i;

    if ( mapp(quest = me->query("quest")) && me->query("quest/quest") == qname)
    {
	if (time()-me->query("quest_time") < quest["duration"])
	{
	    give_reward(me, me, quest);
	    return 1;
	}
	tell_object(me,"很可惜，你没能在规定的时间里完成任务。\n");
	me ->set("quest",0);
	me ->delete("annie_quest");		// just a precaution.
	me ->delete_temp("annie_quest");
    }

    return 1;
}

int give_quest_list(object who, mapping me)
{
    mapping qmirror;
    mixed qex;
    int i/*, num*/, combatexp, max_exp, num_file/*, n1, n2*/, time;
    string tag = "_default";
    string qstr;
    object* mem;
	mapping quest;
	
    int j, k/*, count*/, s;
    mapping *quest_list = ({});
    
    quest_list = allocate(3);

    //	以防万一    
    if(who->is_ghost() || who->is_zombie()) {
		tell_object(who,"鬼魂不可要任务，请立即报告巫师，否则以利用BUG处理。\n");	
		return notify_fail("\n");
    }

    //	现有的Quest还没有完成	
    time = who->query("quest/duration")>1 ? who->query("quest/duration") : 900; 
    if(qex =  who->query("quest") && (time() - who->query("quest_time") < time)) {
		return 0;
    }

    //	Cancel后的下一个时间还没到。	
    if((who->query("next_time")) > time()) {
		return 0;
    }

    max_exp = 0;
    combatexp =0;

    //	找出一个team里经验最高的人员
    mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
    i = sizeof (mem);
    while (i--)	{
	if (mem[i]) {
	    max_exp = mem[i]->query("combat_exp");
	    if (max_exp > 15000000) max_exp = 15000000;
	    combatexp = (max_exp>combatexp) ? max_exp : combatexp;
	}
    }


    //	选择哪个quest文件，注意前两个有可能选空
    num_file = combatexp / 1000;

    
    j = 0;
    k = 0;
       
    while (j <3 && k< 10) {
      	// 最多只有一个 non-normal quest
	    quest = ([]);
	    
	    if (!s) {
		    if(!random(15))	{ 	
				tag = "_repeat";
				if (sizeof(mem)>1) 
			    	quest = QUEST_D(tag)->query_quest(combatexp/1000);
				else {
					quest = QUEST_D(tag+"_solo")->query_quest(combatexp/1000);
		    	}
		    	s = 1;
		    }
	
		    if (!sizeof(quest) || !quest) {
				if (!random(30)) {
				    tag = "_special";
				    if (sizeof(mem)>1)
				    	quest = QUEST_D(tag)->query_quest(combatexp/1000);
					else
						quest = QUEST_D(tag+"_solo")->query_quest(combatexp/1000);
				} 
				s = 1;
			}
		}
		
    //	CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",quest) );	

	    if (!sizeof(quest) || !quest) {
			
			if( num_file < 100) 		tag="_small";		
			else if( num_file <= 1000) 	tag="_middle";
			else if (num_file <= 5000) 	tag="_large";
			else	tag="_super"; 
			
			quest = QUEST_D(tag)->query_quest(combatexp/1000);	
	    }

	    if (tag == "_special" || tag == "_repeat") {
			qmirror = mapping_copy(quest);// nip pointer bug.
			qmirror["quest_des"] = quest["short"];
	//		CHANNEL_D->do_sys_channel("sys",sprintf("%O ?? %O: %s", quest, qmirror, qstr));
	    } else 
	    {
			if (quest["quest_location"])
		    	qstr = HIW"到"+quest["quest_location"];
			else qstr="";
			if(quest["quest_type"] == "寻") {
		    	qstr += HIW"找回『"NOR + quest["quest"] + HIW"』给" 
		    	+ me["employer"] + HIW"。"NOR;
			} else if(quest["quest_type"] == "杀") {
		    	qstr += HIW"替" + me["employer"] + HIW"杀了『"NOR
		    	+ quest["quest"] + HIW"』。"NOR;
			}
			qmirror = mapping_copy(quest);
			qmirror["quest_des"] = qstr;
	    }
	    
	    quest_list[j] = mapping_copy(qmirror);
	    j++;
	    k++;
	}
	
    CHANNEL_D->do_sys_channel("sys", sprintf("%s quest_list is %O",HIW + who->name(), quest_list));

    return 1;
}


int dungeon_reward(object quester, string name, object*	rewardee, int d_bonus)
{
	int team_size, i, level, base/*, n*/, combat_exp, silver, money/*, q_bonus*/, half;
	string reward_msg;
//	object ob;
	object* mem;

	if( name == "垂笠老僧的任务") {
		mem = rewardee;
		team_size = sizeof(mem);
	
		// reward money, 单人　400 bonus 左右 /4 --> gold
		money = d_bonus/4;
		if( team_size ) {
			for( i = 0; i < team_size; i++ ) {
				// 注意，这里用的是F_LEVEL, 直接 query("level")得到的是曾经达到的最高lvl
				level = F_LEVEL->get_level(mem[i]->query("combat_exp"));
				base = REWARD_D->quest_reward(level);

				// 最终奖励经验值。 REWARD CAPPED at 10M, 多余的进入ability或者只用来增加pot
				combat_exp = base*(d_bonus)/100/team_size; // 这里不需要加１００了，d_bonus决定总体奖励

				// Holiday rewards, 50=*0.5, 100=*2, 200=*3 
				combat_exp = combat_exp*(100+query_holiday())/100;
				half = 1;
				if( mem[i]->query("death/half_quest") < 0 ) {
					// 此人有死亡损失
					if( level < 50 && mem[i]->query("death/time")+86400 < time() ) {
						// lv 50级以下，死亡超过24小时，肯定不能revive, 也没有Penalty
						mem[i]->delete("death/half_quest");
						mem[i]->delete("death/exp_lost");
						mem[i]->set("death/revived",1);
						tell_object(mem[i],"恭喜，你的死亡损失在２４小时后自动消失了！\n");
					} else {
						half = 2;
						mem[i]->add("death/half_quest", combat_exp/half);
					}
				}
				combat_exp = combat_exp/half;

				if( mem[i]->query("env/ability") 
					&& F_LEVEL->get_level(mem[i]->query("combat_exp")) >= 80
					&& mem[i]->query("saved_quest")/60/100 < mem[i]->query("learned_ability")+6 ) {
					mem[i]->add("saved_quest", 60*d_bonus/100/team_size/half);
					if( query_holiday() ) {
						mem[i]->add("saved_quest", 60*d_bonus/100/team_size/half*query_holiday()/100);
					}
				} else {
					if( mem[i]->query("combat_exp") >= 10000000 ) {
						mem[i]->add("extra_exp", combat_exp);
					}
					if( mem[i]->query("combat_exp") < 10000000 ) {
						mem[i]->add("combat_exp", combat_exp);
					}
					if( mem[i]->query("combat_exp") >= 10000000 ) {
						mem[i]->set("combat_exp",10000000);
					}
				}

				silver = money / team_size;
				silver = silver/half;
				// 直接入帐．
				mem[i]->add("deposit",silver*100);

				if( mem[i] != quester ) {
					reward_msg =YEL+"在你的协助下完成了"+ quester->name()+"的垂笠老僧任务，你的经验值提高了" + combat_exp + "，奖励" + chinese_number(silver) + "两银子。\n\n" + NOR;
				} else {
					reward_msg =YEL+ "你完成了垂笠老僧的任务，你的经验值提高了" + combat_exp + "，奖励" + chinese_number(silver) + "两银子。\n\n" + NOR;
				}
				tell_object(mem[i], reward_msg);

				if( half == 2 ) {
					if (mem[i]->query("death/half_quest") < 0 ) {
	//					tell_object(mem[i],"（由于你最近的死亡，该任务奖励降为５０％）\n");
	//					tell_object(mem[i],"（按这样的速度，大约还需要" + (-mem[i]->query("death/half_quest")/combat_exp)+ "个任务后就没有惩罚了）\n"); 	
					} else {
						mem[i]->delete("death");
						tell_object(mem[i],"（恭喜，你的死亡损失已经全部消除了！）\n");
					}
				}
			}
		}

		quester->delete("private_maze");
		quester ->set("quest", 0);
		quester->delete("quest_time");
		quester->set("chuili_unfinished", 0); // 看是否完成了垂笠僧任务。
		if( quester->query("cont_quest") < 20 ) {
			quester->add("cont_quest",1);
		}

		quester->add("FINISH_QUEST",1);

	}
	return 1;
}

int set_chance(int num){
	chance = num;
	return 1;
}


int set_level(int num){
	level_chance = num;
	return 1;
}
