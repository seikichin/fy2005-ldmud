// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    	set_name("地匹", ({ "master di", "master"}) );
    	set("nickname", HIY "随缘" NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "男性" );
    	set("reward_npc", 1);
	set("difficulty", 3);
    
    	set("age", 64);
    	set("per", 35);
    	
	set("combat_exp", 1100000);
    	set("attitude","friendly");

    	set("long", "少林第十九代长老，专门传授少林罗汉武功。\n");
    	create_family("少林寺", 19, "长老");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"沙弥","僧人","罗汉","金刚","上人","高僧","大师",
		"长老","法堂长老","戒律院长老","法堂首座","戒律院首座",
		YEL"长老院首座"NOR,YEL"副主持"NOR,YEL"禅宗传人"NOR,HIY"禅宗宗主"NOR}));
		
    	set("class", "shaolin");
    
    	set_skill("move", 120);
    	set_skill("dodge", 120);
    	set_skill("literate", 100);
    	set_skill("unarmed",120);
    	set_skill("puti-steps",120);
    	set_skill("dabei-strike",120);
    	set_skill("zen",120);
    	set_skill("chanting",120);
    	set_skill("xiaochengforce",120);
    	set_skill("parry",120);
    	
        set_skill("foreknowledge",100);
        set_skill("perception",100);
 
         set_skill("force", 140);
 
          set_skill("spear", 150);
    	set_skill("duanhun-spear",150);
          set_skill("staff",150);
    	set_skill("fumostaff",150);
    	set_skill("blade",150);
    	set_skill("lianxin-blade",150);
        set_skill("liuxing-hammer",150);
    	set_skill("hammer",150);
    
    	map_skill("spear","duanhun-spear");
    	map_skill("hammer","liuxing-hammer");
    	map_skill("staff","xingyi-stick");
    	map_skill("parry","lianxin-blade");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "dabei-strike");
    	map_skill("blade","lianxin-blade");
    
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action( "unarmed.qianshouqianbian" ):)
            }) );
    
    	setup();
    	carry_object(__DIR__"obj/monk21_cloth")->wear();

}

void attempt_apprentice(object me)
{
    	if(me->query("class") == "shaolin" && me->query_temp("won_master_meng"))
    	{
		command("smile");
        	command("recruit " + me->query("id") );
        	return;
    	}
    	else
    	{
		command("shake");
    	}
}

int accept_fight(object me)
{
        if( is_fighting() )
		command("say 想倚多为胜？去找寺内的棍僧较量吧！\n");
		
        if(me->query("family/family_name") == query("family/family_name") &&
	   	me->query("family/master_id") == query("id"))
        {
        	if( query("gin") * 100 / query("max_gin") >= 90
			&& query("kee") * 100 / query("max_kee") >= 90
			&& query("sen") * 100 / query("max_sen") >= 90 )
		{
        	       	if (me->query_skill("zen",1) >= 120) {	// 660k
        			command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
        			me->set_temp("marks/fi_m_19",1);
        			return 1;
        		}
        		command("say 徒儿，你的禅道修为太浅，光练武可不行啊！\n");	
        		tell_object(me,"（需120级禅道）\n");		
        	} else
        		command("say 好，不过，让老衲喘口气再来。\n");
        		
        }	
        else
        {
        	command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        	return 0;
        }
        return 1;
}

void win_enemy(object loser)
{
    	if (loser->query_temp("marks/fi_m_19")) {
    		command("say 阿弥陀佛！徒儿还要努力呀！\n");
    		loser->delete_temp("marks/fi_m_19");
    	}
}
void lose_enemy(object winner)
{
    	if (winner->query_temp("marks/fi_m_19")) {
    		command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    		winner->delete_temp("marks/fi_m_19");
    		winner->set_temp("won_master_di",1);
    	}
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}
