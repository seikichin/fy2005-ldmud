// hell_guard.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{
	set_name(YEL"玉清道人"NOR, ({ "sq-taoist"}) );
	set("long", "一位道者，戴如意冠，穿淡黄八卦衣，骑天马而来，一手执灵芝如意。\n");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);	
	set("combat_exp", 100000);	
	set_skill("sword", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);
	set_skill("three-sword",70);
	set_skill("notracesnow",70);
	map_skill("dodge","notracesnow");
	map_skill("sword","three-sword");
	map_skill("parry","three-sword");
	setup();

	carry_object("/obj/armor/armor",
    		([	"name"	:	HIY"淡黄八卦衣"NOR,
    			"value"	:	0,
			"armor_prop/armor"	: 20 ])
    		)->wear();
	carry_object("/obj/weapon/sword",
		([	"name"	:	"灵芝如意",
    			"value"	:	0,	])
		)->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner,*pros;
	if (environment())
	message("vision",CYN"玉清道人化作一道青烟消失了。\n" NOR, environment(),this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("max_guard",-1);
                owner->add_temp("sanqing/sq2",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	                
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i, bonus_skill;
	object *enemy,*pros;

	set("str",10+level/16+random(level/16));
	set("agi",10+random(level/12));
	set("cor",15+random(level/12));
	
	set("max_kee",300+random(level*level/60));
	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("max_gin",query("max_kee")/2);
	set("gin",query("max_kee")/2);
	set("eff_gin",query("max_kee")/2);
	set("max_sen",query("max_kee")/2);
	set("eff_sen",query("max_kee")/2);
	set("sen",query("max_kee")/2);
	
	set("max_force",300+random(level*level/200));
	set("force",query("max_force"));

	
	bonus_skill = 50 + level/4 + random(level/4);
	set_skill("sword", 50 + level/4 + random(level/4));
	set_skill("parry", 50 + level/4 + random(level/4));
	set_skill("dodge", 50 + level/4 + random(level/4));
	set_skill("move", 50 + level/4 + random(level/4));
	set_skill("notracesnow",20 + level/4 + random(level/4));
	set_skill("three-sword",30 + level/4 + random(level/4));
	
	set("combat_exp", 20000 + level/8*level*level/2+random(level/8*level*level/2)); 
	

	pros = who->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	who->set_temp("protectors",pros);
	
    	message_vision(YEL"\n"
"只听得正南上又有钟响，来了一位道者，戴如意冠，穿淡黄八卦衣，骑天马而\n"
"来，一手执灵芝如意，大呼曰：“这位道兄！吾来佐你共伏妖孽！\n"
"说罢吟道：\n"
"    函关初出至昆仑，一统华夷属道门。\n"
"    我体本同天地老，须弥山倒性还存。	吾乃玉清道人是也。\n"NOR,this_object());
    					
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}


void unconcious() {
	die();
}

void die()
{
	object *pros,owner;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("max_guard",-1);
                owner->add_temp("sanqing/sq2",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}                
	message("vision",MAG"玉清道人化作一道紫烟消失了。\n" NOR, environment(),this_object() );
	destruct(this_object());
}


void heart_beat()
{
	object leader;
	
	::heart_beat();
        if(!this_object()) 		return;
	
	if(query_temp("is_unconcious")||is_busy())
		return ;
	if(query("possessed"))
	{
		leader=query("possessed");
		if(objectp(leader) && environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			message_vision("$N匆匆离去。\n",this_object());
			this_object()->move(environment(leader));
			message_vision("$N走了过来。\n",this_object());
			delete("leave_room");
		}
	}
	
	else
	{
		if(!query("leave_room"))
			set("leave_room",1);
		else
			add("leave_room",1);
		if(query("leave_room")==5)
			leave();
	}
}

