
#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit NPC;

int chat()
{
	string *msg;
	int chance, rnd;

	if(!environment() ) return ::chat();
	if(query("intellgent")) intellgent_behavor();
	if( !chance = ({int})query(is_fighting()? "chat_chance_combat":
							 "chat_chance") )
		return ::chat();

	if(pointerp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))
			&& sizeof(msg) != 0) {
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if(stringp(msg[rnd])) {
				say(msg[rnd]);
			} else if(closurep(msg[rnd])) {
				return evaluate(msg[rnd]);
			}
		}
		return ::chat();
	}
	return ::chat();
}

void heart_beat() {
	int wimpy_ratio, to_wimpy, cnd_flag, oldbusy;
	mapping my;
	object ob;
	string savemyass;

	if(!this_object()) {
		return;
	}

//	command("say start heart_beat");
//	command("say i am busy"+({string})query_busy());
	if (query_temp("in_heart_beat"))
		return;

	my = query_entire_dbase();
	
	// If we are dying because of mortal wounds?
	if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0  
			|| my["kee"] < -2 * my["dur"]  || my["sen"] < -2 * my["dur"] || my["gin"] < -2 * my["dur"]) {
		remove_all_enemy();
		die();
		return;
	}
	
	// If we are unconcious, just return;
//	if(query_temp("is_unconcious"))  {
//		return;
//	}
	// 不，我们依然可以做些事
	
	// If we're dying or falling unconcious?
	if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
		remove_all_enemy();
		unconcious();
		return;
	}
	
	
// let NPC do something in fight that won't be affected by busy...e.g talk
//	all actions in nb_chat will be executed in fight. They should never have busy()
//	as a consequence and they should be allowed to appear at same time.

		// (2) chat() may do anything -- include destruct(this_object())
		if(objectp(this_object()) && !userp(this_object())) {
			chat();
			if(!this_object()) {
				return;
			}
		}

	// If busy, continue action and return here.
	if(is_busy()) {
		continue_action();
		return;
	}

	// to clear fighting flag
	if(is_fighting()) {
		clean_up_enemy();
	}

	if(tick--) {
		return;
	} else {
		tick = 5 + random(10);
	}
	
	if (!living(this_object())) return;
	
	// If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P

	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up()) && !is_fighting() 
			&& !interactive(this_object())) {
		if(environment()) {
			ob = first_inventory(environment());
			while(ob && !interactive(ob)) {
				ob = next_inventory(ob);
			}
		}
		if(!ob && !query("ALWAYS_ACTIVE")) set_heart_beat(0);
	}
	if(!this_object()) return;
	if(!interactive(this_object())) return;
	
}


//	this function set NPC with same group starting to protect each other.
//	set("group",xxxx);
//	set("couple",xxxx);

void 	baohu() {
	object me, *pros, *inv, ob;
	string type;
	int i,j, gotit;
	
	pros= ({});
	me= this_object();
	pros = me->query_temp("protectors");

//	message_vision(" in baohu.\n",me);	
	type = me->query("group");
	
	inv = all_inventory(environment(me));
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if ( ob->query("group") != type || ob==me ) continue;
		if (userp(ob) || !ob->is_character()|| ob->is_corpse()) continue;
		
//		message_vision(" looking for a baohu.\n",me);
		
		if (sizeof(pros))
		if (member_array(ob,pros)!=-1) continue;

		if(sizeof(pros))
			pros += ({ ob });
		else
			pros = ({ ob });
//		message_vision(" one baohu is added.\n",me);
	}
	
	me->set_temp("protectors",pros);
//	message_vision(" out baohu.\n",me);
}	

void ask_help() {
	object me, *enemy, *inv, ob;
	string type;
	int i, j;
	
	me= this_object();
	type = me->query("group");
	if (!type) return;
	enemy = me->query_enemy();
	inv = all_inventory(environment(this_object()));
	i=sizeof(inv);
	while (i--) {
		ob = inv[i];
		if (ob->query("group")!=type || ob==me) continue;
		if (userp(ob) || !ob->is_character() || ob->is_corpse()) continue; 
		j= sizeof(enemy);
		while (j--){	
			if (ob->is_fighting(enemy[j])) continue;
			message_vision(HIR"\n$N喝道：这，太过分了吧！\n"NOR,ob);
			ob->kill_ob(enemy[j]);
		}		
	}
}


//	all actions in nb_chat will be executed in fight. They should never have busy()
//	as a consequence and they should be allowed to appear at same time.

int nb_chat()
{
	int total_chance, *chance, i;
	mapping nb_chat;

	if( !environment() ) return 0;
	
	//  NPC starts to help each other.if couple then will protect each other.
	if (query("group")) {
		if (sizeof(query_killer())) ask_help();
		if (query("couple")) baohu();
	}
	
	// NPC starts to defend 
	if (query("defense_type")) {
		if(is_busy()) SMART_D->do_defense(this_object(),query("defense_type"));
			else  SMART_D->do_remove_defense(this_object(), query("defense_type"));
	}
	
	if (random(100)>=query("nb_chat_chance")) return 0;
	
	if (mapp(nb_chat=query("nb_chat_msg_combat"))) {
		chance=keys(nb_chat);
		if (sizeof(chance)) {
			for(i=0;i<sizeof(chance);i++) {
				if ((chance[i])>random(100)) {				
					if (stringp(nb_chat[chance[i]]))
						say(CYN+nb_chat[chance[i]]+NOR);
					else if (closurep(nb_chat[chance[i]]))
						evaluate(nb_chat[chance[i]]);
				}
			}
		}
		return 1;
	}
	return 0;
}

varargs int receive_damage(string type, int damage, object who)
{
	// 不受g/s损伤
	if (type == "gin" || type == "sen")
		return 0;
	return ::receive_damage(type,damage,who);
}

varargs int receive_wound(string type, int damage, object who)
{
	// 不受g/s损伤
	if (type == "gin" || type == "sen")
		return 0;
	return ::receive_wound(type,damage,who);
}

void unconcious()
{
	die();
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
