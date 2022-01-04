// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","龙象殿");			// 	Edge
		room->set("long","\n"
"龙乃八部众神的次位，龙王之中，有一名为沙竭罗龙王，他的幼女八岁时到释 \n"
"迦反牟尼所说法的灵鹫山前，转为男身，现佛之相。她成佛之时，为天龙八部所见。 \n"
"殿中四海龙腾，张牙舞爪，不可一世。 \n"
""
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","乾达婆殿");
		room->set("long","\n"
"乾达婆乃一种不吃酒肉、只寻香气作为滋养的神，是服侍帝释的乐神之一，身 \n"
"上发出浓冽的香气，“乾达婆”梵语中又为“变幻莫测”之意，缥缈隐约，难以捉 \n"
"摸。殿中雕像也神秘诡异，令人不寒而栗。\n"
""
	);
	} else 	if (exit_number==1) {				//	Deadend
		switch (random(3)) {
			case 0:		
				room->set("pos","deadend");
				room->set("short","阿修罗殿");
				room->set("long","\n"
"阿修罗神者，男极俊女奇丑，与帝释为敌。性子暴躁、执拗善妒。释迦牟尼说 \n"
"法，说“四念处”，阿修罗王也说法，说“五念处”；释迦牟尼说法“三十七道品 \n"
"”，阿修罗王偏又多一品，“说三十八道品”。大智度论卷三十五：“阿修罗其心 \n"
"不端故，常疑于佛，谓佛助天。佛为说‘五众’，谓有六众，不为说一；若说‘四 \n"
"谛，谓有五谛，不说一事。” \n"
""
				);		
			case 1:
				room->set("pos","deadend");
				room->set("short","摩呼罗迦殿");
				room->set("long","\n"
"摩呼罗迦为大蟒之神，人身蛇头。殿上四柱擎天而立，四条摩呼罗迦盘柱而上， \n"
"红信四饶，威严肃穆，似离柱而飞。 \n"
""
				);		
			case 2:
				room->set("pos","deadend");
				room->set("short","紧那罗殿");
				room->set("long","\n"
"紧那罗梵语意为“人非人”。形似人，头生角，所以称为“人非人”，善于歌 \n"
"舞，是帝释的乐神。殿中紧那罗飞天善舞，衣袖飘飘，莫辨真假\n"
""
				);		
		}
	
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","迦楼罗殿");
		room->set("long","\n"
"迦楼罗为一大鸟，翅有庄严宝色，头生大瘤，为如意珠，此鸟鸣声悲苦，以龙 \n"
"为食。日嗜一龙及五百小龙。命终日，诸龙吐毒，无法再吃，于是上下翻飞七次， \n"
"至金刚轮山顶上命终。因为其一生以龙为食物，体内积蓄毒气极多，临死时毒发 \n"
"自焚。肉身烧去后只余一心，作纯青琉璃色。\n"
""
	);
	}
}


void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=14) {
		room->set("objects",([				
			__DIR__"npc/sl-monk3": 		!random(5),
			__DIR__"npc/sl-monk3a":		!random(5),
			__DIR__"npc/sl-monk3b":		!random(5),
			__DIR__"npc/sl-sentry": 	!random(10),
		]));		
	} else 	if (x>=7) {
		room->set("objects",([				
			__DIR__"npc/sl-monk2": 		!random(5),
			__DIR__"npc/sl-monk2a":		!random(5),
			__DIR__"npc/sl-monk2b":		!random(5),
			__DIR__"npc/sl-sentry": 	!random(10),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/sl-monk1": 		!random(5),
			__DIR__"npc/sl-monk1a":		!random(5),
			__DIR__"npc/sl-monk1b":		!random(5),
			__DIR__"npc/sl-sentry": 	!random(10),
		]));		
	}
	room->setup();
}
