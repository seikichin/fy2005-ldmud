// go.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

string *area;
mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边高处",
	"southup":		"南边高处",
	"eastup":		"东边高处",
	"westup":		"西边高处",
	"northdown":		"北边低处",
	"southdown":		"南边低处",
	"eastdown":		"东边低处",
	"westdown":		"西边低处",
	"northeast":		"东北",
	"northwest":		"西北",
	"southeast":		"东南",
	"southwest":		"西南",
	"up":			"上",
	"down":			"下",
	"out":			"外",
	"enter":		"里",
]);

mapping area_name = ([ 
		"baiyun"	:	"白云城",
		"bat"		:	"蝙蝠岛",
		"bashan"	: 	"巴山",
		"bawang"	:	"饿虎岗",
		"biancheng"	:	"边城",
		"cave"		:   "风云地下城",
		"chenxiang"	:	"沉香镇",
		"chuenyu"	:	"黑松堡",
		"cyan"		: 	"明霞山",
		"daimiao"	:	"岱庙",
		"death"		:	"鬼门关",
		"eastcoast"	: 	"东海",
		"eren"		:    "恶人谷",
		"eren2"		:    "恶人谷",
		"fy"		:	"风云城",
		"fugui"		:    "富贵山庄",
		"fycycle"	:  	"风云外城",
		"fywall"	:   "风云城",
		"ghost"		:    "幽灵山庄",
		"guanwai"	:  	"关外",
		"guanyin"	:  	"天枫",
		"huangshan"	:	"黄山",
		"huashan"	:  	"华山",
		"jinan"		:    "济南",
		"laowu"		:    "老屋",
		"libie"		:    "无名小镇",
		"loulan"	:   "楼兰",
		"manglin"	:  	"莽林",
		"oldpine"	:  	"老松寨",
		"palace"	:   "帝王谷",
		"qianfo"	:   "千佛山",
		"qianjin"	:  	"千金楼",
		"qingping"	: 	"清平山庄",
		"quicksand"	:	"大沙漠",
		"resort"	:   "铁雪山庄",
		"shaolin"	:  	"少林寺",
		"shenshui"	: 	"神水宫",
		"songshan"	: 	"嵩山",
		"taiping"	:  	"太平镇",
		"taishan"	:  	"泰山",
		"taoguan"	:  	"桃源",
		"taoyuan"	:  	"三清观",
		"tieflag"	:  	"大旗谷",
		"wanmei"	:   "万梅山庄",
		"wolfmount"	:	"狼山",
		"wudang"	:   "武当",
		"xiangsi"	: 	"相思岭",
		"xinjiang"	: 	"新疆",
		"yingou"	:   "银钩赌坊",
		"zhaoze"	:	"沼泽地",
		"zangbei"	:	"藏北",
]); 

void create() {
	seteuid(getuid());
	area=keys(area_name);
}

int drop_things(object me) {
	int i, result;
	object *inv;
	object env;

	env = environment(me);
	inv = all_inventory(me);
	result = 0;
	for(i=0;i<sizeof(inv);i++){
		if(inv[i]->query("no_drop") || inv[i]->query("equipped") || inv[i]->query("owner")
				|| random(me->query_max_encumbrance()) > inv[i]->weight()) {
			continue;
		}
		result = me->ccommand("drop "+inv[i]->query("id")) ? 1 : result;
	}
	if(result) {
		message_vision("慌乱而去。", me);
		return 1;
	}
	return 0;
}


int check_flee(object me, string arg)  {

   	object 	*enemy;
   	int fp, bp, i, level;
   	
   	fp = me->query_agi();
	
	enemy = me->query_enemy();
   	i = sizeof(enemy);
   	while (i--) {
		if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) 
		{
			if (enemy[i]->query("possessed"))		continue;
			if (enemy[i]->query_temp("is_unconcious"))	continue;
			// Since x5 can usually kill 1, Let it not blocking x5.
			if (enemy[i]->query("combat_exp")< me->query("combat_exp")/5) 	continue;
			bp = enemy[i]->query_agi();
			if (fp > bp*2)	continue;	
			if (enemy[i]->is_busy())
				bp = bp * 3/5;
			level = F_LEVEL->get_level(me->query("combat_exp"));
			if ( level <30) fp = fp*3;
			else if (level < 40) fp = fp*2;		
			if((random(fp + bp) < bp)
				|| enemy[i]->query_temp("block_all_escape")) 
			{
				message_vision(YEL "$N向" + arg + "逃去！\n" NOR, me);
				message_vision(RED "$N身影一闪，挡在了$n的面前！\n" NOR, enemy[i], me);
				return 0;
		 	}
	  	}
   	}
   	return 1;
}


int main(object me, string arg) {
	string dest, mout, min, dir,location;
	object env, obj;
	mapping exit,room_info;
       env = environment(me);
	room_info=([]);
	if( !arg ){ 
	me->process_gmcp(room_info,"Move","Info");
	return notify_fail("你要往哪个方向走？\n");
	}

	if( me->over_encumbranced() ){
	me->process_gmcp(room_info,"Move","Info");
	return notify_fail("你的负荷过重，动弹不得。\n");
	
	}

	if( me->is_busy() ){
	me->process_gmcp(room_info,"Move","Info");
	return notify_fail("你现在忙得很，不能移动。\n");
	}

	if (stringp(me->query_temp("no_move"))){
	me->process_gmcp(room_info,"Move","Info");
	return notify_fail(me->query_temp("no_move"));
	}

	if(!env){ 
	me->process_gmcp(room_info,"Move","Info");
	return notify_fail("你哪里也去不了。\n");
	}
	if(env->query_temp("lock_scene"))
	{
		if(time()<env->query_temp("lock_scene")+120){//防止万一没有去掉那个temp mark，出问题。
		me->process_gmcp(room_info,"Move","Info");
		return notify_fail("你感觉到周围被一阵气场紧紧缩住，无法动弹。\n");
		}
	}
	if( !mappingp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go"){
			me->process_gmcp(room_info,"Move","Info");
		return notify_fail("这个方向没有出路。\n");
		}else{
		me->process_gmcp(room_info,"Move","Info");
		return 0;
		}
	}

	
//	在fy4里尚未用到此功能，需要时再说。        
/*      if( mappingp(block = env->query("blocks"))&& blk=block[arg]) {
		if( objectp(blocker = present(blk, env)) &&  living(blocker))
		return notify_fail("这个方向的路被"+ blocker->name() + "挡住了 。\n");
        }*/

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
	{
		if (!load_object(dest))
		{
			tell_object(me,"这间屋子已消失在虚空中．．．\n");
			me->process_gmcp(room_info,"Move","Info");
			if (wizardp(me) && me->query("env/yesiknow"))
				call_other(dest, "???");
			return 1;
		}
//		call_other(dest, "???");
	}
	
	if( !(obj = find_object(dest)) ){
	me->process_gmcp(room_info,"Move","Info");
	return notify_fail("无法移动。\n");
	}

/*	if (userp(me) && ANNIE_D->check_buff(me,"fugitive")>0
		 && (obj->query("no_fight") || obj->query("no_death_penalty")))
		return notify_fail("你身负重案，那些地方不敢收留你呀！\n");*/
	
	if (env)
	if (!env->valid_leave(me, arg) ) {
		me->process_gmcp(room_info,"Move","Info");
		return 0;
	}
	 
	if( !undefinedp(default_dirs[arg]) )
			dir = default_dirs[arg];
		else if (dest->query("short")) dir=dest->query("short");
		else dir = arg;

	if( me->is_fighting() ) {

		if (ANNIE_D->check_buff(me,"lockfield") >= 1)
		{
			tell_object(me,YEL"你眼前的景物似真似幻，游移不定，难以确定道路究竟是在何方。\n"NOR);
			me->process_gmcp(room_info,"Move","Info");
			return 0;
		}

		if (me->query_temp("timer/no_escape") > time()){
		me->process_gmcp(room_info,"Move","Info"); 
		return notify_fail("你现在不能逃跑！\n");
		}

		// 每3个heart_beat里只有一次逃跑的尝试可能成功。
		if (me->query_temp("marks/escape") + 6 > time()) {
			me->process_gmcp(room_info,"Move","Info");
			return notify_fail("你被挡了回来。\n");
		}
		if(check_flee(me, dir) == 0) {
			me->set_temp("marks/escape",time());
			me->process_gmcp(room_info,"Move","Info");
			return notify_fail("你被挡了回来。\n");
		}
		if (me->query("timer/insurance") + 259200 < time())
			drop_things(me);
		
		if (me->query("fleeout_message")) {
		    mout = replace_string( me->query("fleeout_message"), "$d", dir );
		    mout = mout + "。\n";
		 }
         else 
         	mout = "往" + dir + "落荒而逃了。\n";
         if (me->query("fleein_message")) 
         	min  = me->query("fleein_message") + "。\n";
         else  
         	min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";

	} else {
// Let's add this messages here to make go and come more interesting...
		if( mout = me->query("leave_msg"))
			mout = "往" + dir + mout +"。\n";
		else 
			mout = "往" + dir + "离开。\n";
		if( min = me->query("arrive_msg") )
			min = min + "。\n";
		else
			min = "走了过来。\n";
	}
	
	if (userp(me))
	if (obj->query("underwater") > me->query_skill("swimming",1)){
		me->process_gmcp(room_info,"Move","Info");
	return notify_fail("你的游泳技能太差，没法过去呀（需要技能"+obj->query("underwater")+"级）\n");
	
	}
		
	if (!userp(me) && obj->query("NONPC"))
		return notify_fail("你不可去那里。\n");
	else if( function_exists("valid_enter", obj) && !obj->valid_enter(me)){
		me->process_gmcp(room_info,"Move","Info");
	return notify_fail("你不可去别人的私宅。\n");
	}
		
	if(!me->is_ghost())
		if( me->query("self_go_msg") )		// this is for 自定义的不带主语的离开
			message( "vision", me->query("leave_msg")+"\n", environment(me), ({me}) );
		else if (me->query("env/invisibility"))
			message("vision","似乎有什么东西一闪后不知向什么方向去了。\n",environment(me),({me}));
		else  message( "vision", me->name() + mout, environment(me), ({me}) );

	if( me->move(obj) ) {
		
		me->remove_all_enemy();
		if(!me->is_ghost())
			if( me->query("self_go_msg") )	// this is for 自定义的不带主语的进入
				message( "vision", me->query("arrive_msg")+"\n", environment(me), ({me}) );
			else if(me->query("env/invisibility"))
				message("vision","似乎有什么东西闪了进来。\n",environment(me),({me}));
			else	
				message( "vision", me->name()+ min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		
		if(env)
		if(environment(me) != env) {
			all_inventory(env)->follow_me(me, arg);
		}
		
		location=domain_file(file_name(environment(me)));
		if (member_array(location,area)==-1){	
		location="未知";}
		else {
		location=area_name[location];
		}
           room_info=([
		"name":remove_ansi(environment(me)->query("short")),
		 "exits":keys(environment(me)->query("exits")),
		  "area":location,
		]);
		
		me->process_gmcp(room_info,"Room","Info");
		return 1;
	}
	if(userp(me))
       me->process_gmcp(room_info,"Move","Info");
	return 0;
}


void do_flee(object me) {
	mapping exits;
	string *directions;

	if(!environment(me) || !living(me)) {
		return;
	}
	exits = environment(me)->query("exits");
	if(!mappingp(exits) || !sizeof(exits)) {
		return;
	}
	directions = keys(exits);
	if (!me->query_temp("no_flee_msg"))
		tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}




int help(object me) {
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	go <方向>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"让你往指定的方向移动。\n"
"\n"
"你可以在战斗中用此指令尝试逃离当前房间，\n"
"１。逃离的几率直接取决于战斗双方的相对敏捷度\n"
"２。在对手忙乱（ｂｕｓｙ）时你的逃跑几率增大４０％\n"
"３。每三个战斗回合只能有一次逃跑尝试可能成功\n"
"（也就是说，即使你在六秒钟内连着输入100个go，系统只根据第一个来判断）\n"
"４。在低等级时（Ｌ４０前）增加逃跑几率１０％－２５％\n"
"\n"
"数值计算及说明：a = 逃跑者速度；b = 敌人速度\n"
"当ｒａｎｄｏｍ(a + b ) < b 时，逃跑失败\n"
"\n"
"１．如果敌人处在昏迷状态，逃跑必然成功\n"
"２．如果敌人经验值低于逃跑者的２０％，逃跑必然成功\n"
"３．如果ａ＞２ｂ，逃跑必然成功\n"
"４．如果敌人处在忙乱状态，ｂ*６０％\n"
"５．如果逃跑者等级低于３０，ａ*２\n"
"６．如果逃跑者等级低于４０，ａ*２\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
""
	);
	return 1;
}