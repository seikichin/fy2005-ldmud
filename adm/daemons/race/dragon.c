//	龙

#define BASE_WEIGHT 100000
inherit F_DBASE;
inherit F_LEVEL;

void	race_basic_setup(object ob);

// You are free to add more beast actions here :D
mapping combat_action =
([
	"dragonslash": ([
		"action":		"$N张鳞鼓鬣，跃至$n身前，龙爪往$n的$l一扫",
		"damage":		100,
		"parry" :		400,
		"dodge" :		400,
		"damage_type":	"抓伤",
	]),
	"dragonbreath": ([
		"action":		"$N一口浊气喷出，顿时天昏地暗，无数飞沙走石铺天盖地地向$n飞去",
		"damage":		100,
		"parry" :		200,
		"dodge" :		200,
		"damage_type":	"瘀伤",
	]),
	"dragonbite": ([
		"action":		"$N张开血盆大口，冷不防向$n的$l一口咬下",
		"damage":		400,
		"parry" :		400,
		"dodge" :		100,
		"damage_type":	"咬伤",
	]),
	"dragonswing": ([
		"action":		"$N侧过巨大的身躯，龙尾在空中划个旋，以雷霆之势向$n猛击而下",
		"damage":		200,
		"parry" :		500,
		"dodge" :		100,
		"damage_type":	"抓伤",
	]),
	"dragonthrow": ([
		"action":		"$N深吸一口气，身躯仿似又长大了数倍，猛然间金光闪耀，数片龙鳞向$n的$l击到",
		"damage":		200,
		"parry" :		100,
		"dodge" :		400,
		"damage_type":	"抓伤",
	]),
	"dragonpoke": ([
		"action":		"$N巨首左右摆动，龙须若数十根钢针，夹着风雷之势向$n的$l刺去",
		"damage":		100,
		"parry" :		100,
		"dodge" :		100,
		"damage_type":	"抓伤",
	]),
]);


void create()
{
	seteuid(getuid());
	set("attitude", "peaceful");
	set("limbs", ({ 
		"龙头", "龙身", "龙尾", "龙爪","龙角", "龙须","龙背" 
	}) );
	set("verbs", 	({ "dragonslash", "dragonbreath","dragonbite","dragonswing","dragonthrow","dragonpoke" }) );
	set("death_msg",       		"\n$N发出震天动地的吼声，轰然倒下。。。。\n"    );
	set("leave_msg",    		"向空中一跃，腾云而去"				      );
	set("arrive_msg",     		"挟着风云之势从云间落下"	                      );
}


void setup_animal(object ob)
{
	mapping my;
	my = ob->query_entire_dbase();

	race_basic_setup(ob);
	
	my["unit"] = "条";
	if(undefinedp(my["gender"]) ) my["gender"] = "雄性";
	if(undefinedp(my["spi"])) my["spi"] = 0;	
	if(undefinedp(my["age"])) my["age"] = 1000 + random(1000); 
	if(undefinedp(my["per"])) my["per"] = 5;
	
	ob->set_default_object(__FILE__);
	ob->set("default_actions", (: call_other( __FILE__, "query_action",this_object()) :));	
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 200);
	
		
}

mapping query_action(object me)
{
	string *act;

	act = me->query("verbs");
	return combat_action[act[random(sizeof(act))]];
}


void	race_basic_setup(object ob)
{
	mapping my;
	int combat_exp, bonus, npc_str, npc_att;
	int n, npc_force, npc_f_factor, temp_damage;
	int *extra_d, num,tough;
	mapping extra = ([]);
			
	my = ob->query_entire_dbase();
			
//	Setting up char EXP as well as corresponding level
	if (!my["combat_exp"] || my["combat_exp"]< 2000) my["combat_exp"] = 2000;
	combat_exp = my["combat_exp"];
	my["level"] = F_LEVEL->get_level(combat_exp);
		
// 	Setting NPC default attributes, the bonus will be added to the base
//	... Remember the new PLAYER == !userp(ob) before the first setup !
	if (!userp(ob)) {
		n= combat_exp/100000;	// 10
	//	<100k, NPC is in fact weaker than PC,
		if (combat_exp<100000) {
			npc_str = 10 + random(5); 			
			npc_att = 10 + random(5);    			
			npc_force = (combat_exp <= 10000)? 0: combat_exp*250/100000;	// 250 
			npc_f_factor = npc_force/20;
		}	
		
	//	100k-1M, PC should have finished 45-100force, and 100-120 unarmed. 
		else if (n<=10 && n>=1) {
			npc_str= 11 + n*12/10 + random(n); 	// 11-23 (+10)
			npc_att= 10 + n*12/10 + random(n/2);  	// 11-22 (+5).
			npc_force = 200 + 50*n ;				// 250-700
			npc_f_factor = 20 + n*3 + random(n);	// 23 - 50 +(10)				
		}
			
	//	1-3M, PC should have 160 unarmed, 120-170 force, and full menpai force
		else if (n<=30 && n>10) {
			npc_force = 500 + n*20;								// 700-1100 full guyupai etc
			npc_str = 29 + (n-10)/2 + n/10 + random(n-10)/4;	// 30- 42 (+5)
			npc_att=  20 + (n-10)/2 + random(n-10)/2;			// 20 -30 (+10)
			npc_f_factor = 40 + n + random(10);					// 50 -80 (+9)
			
		}
		
	//	3-5M, PC should have 180 unarmed, 200 force, and full menpai force
	//	NPC starts to be better than PC.	
		else if (n<=50 && n>30) {
			npc_force = 1000+ n*6;					// full guyupai etc 1200-1300
			npc_str = 42 + n/10 +random(n-30)/4;	// 45-47 (+5)
			npc_att=  35 + random(n-30)/2;			// 35 	 (+10)
			npc_f_factor = 90 + n/6 + random(n);	// 95 - 99 (+50)
			
		}
		
	//	5M-10M NPC will have longer gin/kee/sen, this is by design
		else if (n>50 && n< 120) {							// count up to 10M for PCs below
			npc_force =  500 + 20*n;						// 1500 - 2900
			npc_str= 40 + (n-50)/5 + random(n-50)/7 + n/10;	// 45-65 + random(10)
			npc_att= 35 + (n-50)/5 + random(n-50)/5;		// 35-45 + random(15)
			npc_f_factor = 100 + random(n-50);				// 100 (+50)
	
	//	此类ＮＰＣ最好就是单独在文件里定义了		
		} else {
			npc_force =  3000;			
			npc_str= 60 + random (10) + n/10;			// 70+
			npc_att= 45 + random(30);					// 45 +30
			npc_f_factor = 140 + random(30);			// 140 +30
			
		}
		
	
//	Adding attributes bonus to NPCs

		if(npc_f_factor)
		if(undefinedp(my["force_factor"])) 
			my["force_factor"] = npc_f_factor> 150 ? 150 : npc_f_factor;
		
		if(undefinedp(my["str"])) my["str"] = npc_str;
		
		if(undefinedp(my["con"])) my["con"] = npc_att;
		if(undefinedp(my["int"])) my["int"] = npc_att;
		if(undefinedp(my["cps"])) my["cps"] = npc_att;
		if(undefinedp(my["kar"])) my["kar"] = npc_att;
		if(undefinedp(my["agi"])) my["agi"] = npc_att;
		
		if(undefinedp(my["cor"])) my["cor"] = npc_att;
		if(undefinedp(my["dur"])) my["dur"] = npc_att;
		if(undefinedp(my["spi"])) my["spi"] = npc_att;
		if(undefinedp(my["fle"])) my["fle"] = npc_att;
		if(undefinedp(my["tol"])) my["tol"] = npc_att;
		
		if(undefinedp(my["max_force"])) my["max_force"]= npc_force;
		if(undefinedp(my["force"])) my["force"]= npc_force;
		if(undefinedp(my["max_mana"])) my["max_mana"]= npc_force;
		if(undefinedp(my["mana"])) my["mana"]= npc_force;
		if(undefinedp(my["max_atman"])) my["max_atman"]= npc_force;
		if(undefinedp(my["atman"])) my["atman"]= npc_force;		
		
		if(undefinedp(my["score"])) my["score"] = 0;
	
	}
		
//	Setting NPC and PC Gin/Kee/Sen,

	if (!userp(ob))
	{
		tough = ob->query("toughness");
		if ((my["level"]>80 && !tough)) {
			tough = my["level"] + 20;
			my["innate_tough"] = tough;
		}
	} 
	
	if(userp(ob) || undefinedp(my["max_gin"])) {
		my["max_gin"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_atman"] > 0) {
			my["max_gin"] += my["max_atman"] * 2 ;
		} else
			my["max_atman"] = 0;
	
		my["max_gin"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
			
		my["max_gin"] += F_ABILITY->check_ability(ob,"gin",0) * 100;
		
		if (!userp(ob) && tough)	my["max_gin"] = my["max_gin"] * tough /100;	
		
	}
	
	if(userp(ob) || undefinedp(my["max_sen"])) {
		my["max_sen"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_mana"] > 0) {
			my["max_sen"] += my["max_mana"] * 2 ;
		} else
			my["max_mana"] = 0;
	
		my["max_sen"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
			
		my["max_sen"] += F_ABILITY->check_ability(ob,"sen",0) * 100;
		
		if (!userp(ob) && tough)	my["max_sen"] = my["max_sen"] * tough /100;	
	}
	
	if(userp(ob) || undefinedp(my["max_kee"])) {
		
		my["max_kee"] = my["con"]*my["con"] + my["str"] * my["str"]/4;
		
		if(my["max_force"] > 0) {
			my["max_kee"] += my["max_force"] * 2;
		} else
			my["max_force"] = 0;
		
		my["max_kee"] += ( my["con"] + my["str"]/2) *  my["level"] * my["level"] /300;

		my["max_kee"] += F_ABILITY->check_ability(ob,"kee",0) * 100;
		
		if (!userp(ob) && tough)	my["max_kee"] = my["max_kee"] * tough /100;	

	} 	
		
	return;
}
