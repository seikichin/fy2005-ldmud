inherit NPC;
#include <ansi.h>
void afei_help(object player, object yiku);
void  smart_fight(object who);
int imbue_event(object me);

void create()
{
        set_name("伊哭", ({ "yi ku" }) );
        set("title",HIC"青魔手"NOR);
        set("gender", "男性" );
        set("long","他身上穿着件青布袍，大袖飘飘，这件长袍无论穿在谁在身上都\n"
"会嫌太长，但穿在他身上，布还盖不到他的膝盖。他本就已长得吓人，\n"
"头上却偏偏还戴着顶奇形怪状的高帽子，骤然望去，就象是一棵枯树。 \n"
"\n"
"但更可怕的却是他的眼睛，那不像是人的眼睛。 他的眼睛竟是青色的，\n"
"眼球是青色的，眼白也是青色的，一闪一闪的发着光。\n\n"
                );
                
        set("age", 42);

        set("class","yinghe");
        
    	set("no_busy",5);
    	set("no_arrest",1);

        set("pursuer", 1);
        set("attitude", "peaceful");
    
        set_skill("move", 200);
        set_skill("spells", 600);
        set_skill("dodge", 140);
        set_skill("force", 140);
        set_skill("unarmed",200);
        set_skill("devil-spells",600);
        set_skill("puti-steps",140);
        set_skill("dabei-strike",140);
        set_skill("dabei-fu",200);
        set_skill("xiaochengforce",140);
        set_skill("nine-moon-claw",200);
        set_skill("iron-cloth",200);
        set_skill("jin-gang",200);
        map_skill("iron-cloth","yijinjing");
        map_skill("dodge", "puti-steps");
        map_skill("spells", "devil-spells");
        map_skill("unarmed", "dabei-fu");
        map_skill("force", "xiaochengforce");

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        	(: smart_fight(this_object()) :),     
        }));
                
        set("combat_exp", 6500000);
        
        setup();
        carry_object(BOOKS"skill/devil-spells_60")->wield();
        carry_object(__DIR__"obj/high_hat")->wear();    
        carry_object(__DIR__"obj/cyn_cloth")->wear();   
        
}

void init()
{
    	::init();
    	//  I am so kind.. i want to give you reward :D
    	if (REWARD_D->imbue_check(this_player(),"快剑阿飞")
    		&& REWARD_D->check_m_success(this_player(),"快剑阿飞"))	return;
    	if (is_fighting()) return;
    	if (this_player()->query("marks/邱独") ){
        	say("伊哭厉声喝道：好，丘独一命换你一命，也算死得不冤了。！\n");  
        	this_player()->delete("marks/邱独");
        	this_object()->kill_ob(this_player());
        	if (REWARD_D->riddle_check(this_player(),"快剑阿飞")) {
                	call_out("afei_help", 10, this_player(),this_object());
                	delete_temp("afei_helping");
                	add_temp("afei_helping", this_player());
	        }
    	}
}


int do_killing(string arg)
{
	return 0;
}


void killed_enemy(object who)
{
   	command("say 真是找死！再来再杀!!!\n");
}

void unconcious()
{
	die();
    	return ;
}

void die()
{
    	int gin,kee,sen;
    	object killer, afei, room;

	if (query("immortal"))
	{
	        gin =({int})query("max_gin");
	        kee =({int})query("max_kee");
	        sen =({int})query("max_sen");
	        set("eff_kee",1);set("kee",1);
	        set("eff_gin",gin);set("gin",gin);
	        set("eff_sen",sen);set("sen",sen);
		return;
	}

    	killer = query_temp("afei_helping");
    	if( objectp(killer) ){
        	if( environment(killer) == environment() && killer->is_busy() )
                	killer->set("marks/kill_yiku", 1);
    	} 
   
    	afei = present("afei",environment());
              
    	if( objectp(afei) && domain_file(base_name(afei)) == "qianjin" ){
        	room=find_object(AREA_QIANJIN"jinge");
        	if(!objectp(room))
             		room=load_object(AREA_QIANJIN"jinge");
//    message_vision("$N冷冷地哼了一声，转身匆匆离开。", afei);
        	if (!present("afei",room)) afei->move(room);
        	else destruct(afei);
    	} 
    	::die();
}

void afei_help(object player, object yiku) 
{
        object afei, room;
        if (present("afei",environment())) return;
        if (environment(player) == environment() && player->is_fighting(this_object()))
	{
                room=find_object(AREA_QIANJIN"jinge");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"jinge");
                afei = present("afei", room);
                if (objectp(afei)) 
		{
                    	message_vision(HIG"\n阿飞似乎忽然听到了什么动静．．．\n阿飞对林仙儿道：我下去看看，马上就回来陪你。\n\n", afei);
//                        afei->move(environment());
                    	message_vision(BLU"\n蠕动的蓝火从$N脚下蜿蜒游动而起。\n\n"HIC"一条条蠕动的蓝火如蟒蛇般缠上了$N。\n\n"NOR"( "RED"$N已经陷入半昏迷状态，神智全失，如风中残烛，随时都可能断气。"NOR" )\n\n"NOR, player);
                    	player->set("kee",player->query("max_kee")/100+random(player->query("max_kee")/100));
                    	player->set("eff_kee",player->query("max_kee")/50+random(player->query("max_kee")/50));
			player->start_busy(12);
			player->remove_all_killer();
			start_busy(99);
			remove_all_killer();
			environment()->set("no_fight",1);
			call_out("afei_help_2",1,player,afei);
		}
	}
}

// enable 1200 spells, soul-flame damage
// gin = ( 1200 *3/2 *65/27 = 4333
// kee = (1200*2 + 50) *65/27 = 5898
// sen = (1200*4/3 *65/27 = 4792

void smart_fight(object who)
{
			who->cast_spell("soul-flame");
			who->stop_busy();
}



string *event1_msg=     ({
CYN"\n伊哭看了一眼阿飞，狞笑道：你就是林仙儿身边的那个少年？\n"NOR,
CYN"\n阿飞目中突然射出了刀一般锐利的光，道：你若再叫她的名字，我只得杀你了。\n"NOR,
CYN"\n伊哭道：为什么？\n"NOR,
CYN"\n阿飞道：因为你不配。\n"NOR,
CYN"\n伊哭格格的笑了起来，道：我不但要叫她的名字，还要跟她睡觉，你又能怎样！\n"RED"\n阿飞的脸突然燃烧了起来，他的手已因愤怒而发抖，剑已刺出！\n\n"MAG"伊哭的青魔手已雷电般击下，只听叮的一声，剑已被架开。\n"NOR,
CYN"\n伊哭的大笑声刚发出，出手稍慢，突有剑光一闪。\n\n"NOR,
YEL"\n阿飞拭去剑上的血迹，缓缓的离开了。\n"NOR,
YEL"\n伊哭的喉咙里还在格格的响，连眉毛和眼睛也据曲起来，因为他想笑，还想告\n诉阿飞：你迟早也要死在她手上的。\n\n只可惜他这句话永远都说不出来了。\n"NOR,
});

void afei_help_2(object player, object afei) 
{
        object room;
        if (present("afei",environment())) return;
        if (environment(player) == environment())
		{
                room=find_object(AREA_QIANJIN"jinge");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"jinge");
                
                if (environment(afei) == room) 
				{
                    message_vision(HIG"\n$N急匆匆的离开了。\n\n", afei);
                    afei->move(environment());
                    message_vision("\n$N走了过来。\n\n"CYN"$N皱了皱眉，对伊哭道：这是我的朋友，今天我却不愿杀人，你走吧。\n"NOR,afei);
					call_out("event1",1,afei,player,0);
				}
		}
}

void event1(object me, object player, int count)
{
        if (environment(me)!=environment(this_object()) )
			me->move(environment(this_object()));
		
        message_vision(event1_msg[count],me);
		count++;
        if(count==6)
        {
	    	set("combat_exp",1);
	    	set("eff_kee",1);
	    	set("kee",1);
	    	set("immortal",1);
			environment(this_object())->set("no_fight",0);
            		me->kill_ob(this_object());

	       		me->perform_action("sword.sharenruma"); 

			environment(this_object())->set("no_fight",1);
	    	set("eff_kee",1);
	    	set("kee",1);

			message_vision(WHT"\n伊哭平生从未见过如此快的剑光，等他看到这剑光时，剑已刺入了他的咽喉，他\n喉咙里格格作响，面上充满了惊惧和怀疑不信之色。\n\n"YEL"阿飞的目光如寒冰，瞪着伊哭一字字道：谁侮辱她，谁就得死。\n"NOR,me);
		}

        if(count==sizeof(event1_msg))
        {
	    	set("immortal",0);
			environment(this_object())->set("no_fight",0);
				
			REWARD_D->riddle_done(player,"快剑阿飞",100,1);
			
			if(!REWARD_D->imbue_check(player,"快剑阿飞")){
				message_vision(HIR"\n\n血溅，伊哭倒地！\n"NOR,player);
				player->start_busy(3);
				imbue_event(player);
			}
			
			die();
            		return;
        }
        else call_out("event1",1,me,player,count);
        return ;
}



int heal_up()
{
	if(environment() && !is_fighting() && !is_busy()
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

int imbue_event(object me){
//	object weapon,ob,*inv,obj;
//	string prop;
//	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != environment(this_object())) {
		return 0;
	}

	data = ([
		"name":		"快剑阿飞",
		"target":	me,
		"att_1":	"con",
		"att_1c":	1,
		"mark":		1,
	]);
	
	REWARD_D->imbue_att(data);	
	return 1;
}