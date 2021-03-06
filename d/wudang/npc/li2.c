inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack();


void create()
{
        set_name("李萼华", ({ "li ehua" }) );
        set("gender", "女性");
        set("age", 25);
        set("title",HIY"真武门人"NOR);
        set("nickname",HIG"神在剑先"NOR);
        set("long",
"一个伶俐的少女，身着白衣，迎风而立，手里一柄长剑，分量不轻。\n"
"相传李氏兄妹是真武大帝的关门弟子，一手太极剑法当世无敌，所欠只\n"
"是火候而已。双剑合璧，曾困死了点苍派第七代掌门人天南剑容。曾有\n"
"人向西门吹雪请教破李氏兄妹剑阵之法，西门苦思三日，答曰：以武技\n"
"论，此阵无懈可击，唯有凭无上真力才能破阵而出。\n\n"
);
	  
        set("attitude", "friendly");
        set("reward_npc", 1);
	set("difficulty",1);
	set("class","wudang");
        
        set("combat_exp", 1600000);        
        
         set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        
        set_skill("perception",200);  
        set_skill("move", 120);
        set_skill("force", 120);
        set_skill("unarmed", 180);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("spells",100);
        set_skill("qixing",100);                         
        set_skill("taijiforce", 150);
	set_skill("five-steps",150);
	set_skill("taiji",170);
        set_skill("taiji-sword",160);
        
        map_skill("spells","qixing");
        map_skill("unarmed","taiji");
        map_skill("force", "taijiforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("parry","taiji-sword");
        map_skill("sword","taiji-sword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object(__DIR__"obj/heavysword")->wield();
	carry_object("/obj/armor/cloth")->wear();
}

 
void init()
{
        object ob;
        ::init();
	add_action("do_killing","kill");
}

int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen;

    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "li zhihua" && player->query("combat_exp")>3400000)
        {
            message_vision(
"$N叱道：强敌来犯,联手御敌,布两仪剑阵！\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
}

smart_fight()
{
	int j,i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	
	for(j=0;j<sizeof(enemy);j++)
	{
		if (enemy[j]->is_zombie() && random(2))
		{	who->cast_spell("zombie-bolt");
			return;
		}		
	}
	who->smart_attack();
	return;
}

smart_attack() {
	if (this_object()->query_temp("weapon"))
		this_object()->perform_action("sword.chanzijue");	
		else this_object()->perform_action("unarmed.nianzijue");	
	return;
	}
