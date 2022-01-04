/*

Reminder: PPL's corpses will be moved to /d/fy/hiretem when maze is destructed

		if ( num>1)		// Team has several possibilities
			switch (random(num+1)) {
				case 0:		nn = 2;	act[2] = "此事机密无比，你需单身前往。";break;		// Single dungeon, only owner can enter
				case 1: 	nn = 3; act[3] = "此事甚为机密，不宜人多。";break;		// 2ppl limit
				case 2: 	nn = 4;	act[4] = "";	break;	// No limit on boss, but narrow passage for 1 ppl somewhere in dungeon.
				default:	nn = 5;	act[5] = "";	break;	// No limit, normal dungeon, NPC scaled to ppl number
		}else {
			nn = 1;
			act[1] = "";
		}				// single normal dungeon	
*/

inherit ROOM;
#include <ansi.h>
object *get_players();
void setup_room_desc( int x, int y,int z);
string owner;
void create(){

}
void setup()
{
	if( !query("entry_room") && !query("exit_room"))
	 setup_room_desc(this_object()->query("maze/x"),this_object()->query("maze/y"),this_object()->query("maze/z"));
}


void setup_room_desc(int x, int y,int z) {
	
	int exit_number;
	string name;
	if (z == 1)
		name = "天";
	else
		name = "地";
	
	if (y == 0)
		name += "南";
	else if (y == 1)
		name += "中";
	else
		name += "北";

	if (x == 0)
		name += "西";
	else if (x == 1)
		name += "中";
	else
		name += "东";

	exit_number= sizeof(this_object()->query("exits"));
	if (exit_number == 3)
		name += "门";
	else if (exit_number == 2)
	{
		if (random(2))
			name += "路";
		else
			name += "道";
	}
	else
			name += "角";


	this_object()->set("short",HIB BLK+name+NOR);
	
}
void init()
{
	object boss,user,blocker,room2;
	int diff, type;
	owner=FUBEN_D->query_fuben_owner(this_player());
//	user=find_player(query("owner"));

	if (query("entry_room")) {
		add_action("do_out","out");
	}
	
	if (query("exit_room")) {
		add_action("do_burn","burn");	
	}
	if(query("maze/box")){
	   add_action("do_get1","get");
	   write("add_action\n");
	}
	/*
			room2->set("maze/owner", me);
			room2->set("maze/exp", s_quest[i]["exp"]); 
			room2->set("maze/exit", me->query("private_maze/destination"));
			room2->set("maze/name", me->query("private_maze/orig_name"));
			room2->set("maze/boss","/obj/dungeon/boss");	
			room2->set("maze/blocker","/obj/dungeon/blocker");	
	*/
	
	seteuid(getuid());
	
	room2 = find_object("/f/ultra/"+owner+"/maze/entry");
	if (!room2) {
		write ("something is wrong, call wizards, error 32323\n"+owner+"\n");
		return ;
	}
	type = room2->query("maze/type");

/*	type :
	act[1] = "此事机密无比，你需单身前往";		break;		// Single dungeon, only owner can enter
	act[2] = "该处甚为凶险，最好找个帮手";		break;		// 2ppl limit, bandit/boss is a bit harder
	act[3] = "该处极为凶险，最好携三两帮手同行";	break;	// 3ppl limit, 2 blockers per spot
*/
	
	if (query("exit_room") && !query("exist"))	// 不可以放在setup-exit裡
	{
		boss=clone_object(room2->query("maze/boss"));
		if (!boss){
			 notify_fail("Error #13765. Please call wizard.\n");
			 return ;
			 }
		set("exist",1);
		
		boss->set("maze/name",room2->query("maze/name"));
		if (type == 3) {
			boss->set("attitude", "aggressive");
			if (room2->query("maze/exp")>= 7000000)
				boss->set("dd",2);
		}

		boss->invocation(room2->query("maze/exp"));
		boss->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));		
		boss->move(this_object());

/*		CHANNEL_D->do_sys_channel("sys",sprintf("created one %O %d\n", 
				room2->get_players(),sizeof(room2->get_players())
				));*/
				
		if(type == 3 || (type == 2 && random(2)) || sizeof(room2->get_players())>1 ) {
			blocker=clone_object(room2->query("maze/blocker"));
			blocker->set("maze/name",room2->query("maze/name"));
//			if (type == 3  && room2->query("maze/exp")>= 7000000)	blocker->set("dd",2);
			blocker->invocation(room2->query("maze/exp"));
			blocker->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));
			blocker->move(this_object());
		}	
	}

	if (!query("exit_room") && !query("exist") && !query("entry_room"))	// 不可以放在setup-exit裡
	{
				
		blocker=clone_object(room2->query("maze/blocker"));
		if (!blocker){
			 notify_fail("Error #13764. Please call wizard.\n");
			 return ;
			 }
		set("exist",1);
		
		blocker->set("maze/name",room2->query("maze/name"));
		if (type == 1)
			blocker->set("toughness",65);
		else if (type == 2)
			blocker->set("toughness",80);					
		blocker->invocation(room2->query("maze/exp"));
				
		if ( type == 3) {
			blocker->set("attitude","aggressive");
		}

		blocker->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));
		blocker->move(this_object());
		set("blocker",blocker);
	
		if (type == 3 || (type==2 && !random(5-sizeof(room2->get_players())))) {
			blocker=clone_object(room2->query("maze/blocker"));
			blocker->set("maze/name",room2->query("maze/name"));
			if (type == 3  && room2->query("maze/exp")>= 7000000)	blocker->set("dd",2);
			blocker->invocation(room2->query("maze/exp"));
			blocker->set("chat_chance_combat", room2->query("maze/npc_pfm_chance"));			
			blocker->move(this_object());
		}
	}
	return ;
}
int valid_leave(object obj, string dir){
	object ma;
	if(dir == "west"){
		if(present("bandit leader", this_object())){
			ma = present("bandit leader", this_object());
			return notify_fail(ma->name()+"闪身挡住了你的路。\n");
		}
	}	
	return 1;
}
int valid_enter(object who){
	
	if (!query("entry_room") && !environment(who)->query("exit_room") && !environment(who)->query("entry_room")&& !environment(who)->query("trap_room"))
		return (environment(who)->query("cleared")|| query("cleared"));
	else
		return 1;
}

int do_out()
{
	object me = this_player();
	object room, e_room;
	
	room = environment(me);
	if (!room->query("maze/exit")
		|| !(e_room = find_object(room->query("maze/exit"))))
		
		return notify_fail("Error #13766. Please call wizard.\n");
	
	me->move(e_room);
	return 1;
}


object *get_players(){
return FUBEN_D->query_fuben_players("ultra",owner);
}


/*

obj/dungeon/standardmaze/silencer/entry->query("maze") = ([ sizeof() == 11
  "reward" : 1,
  "npc_killed" : 3,
  "type" : 2,
  "npc_pfm_chance" : 30,
  "blocker" : "/obj/dungeon/blocker",
  "exp" : 7000000,
  "boss" : "/obj/dungeon/boss",
  "sig" : obj/dungeon/standardmaze,
  "pwd" : 123,
  "name" : "魔枪鳄腾宫",
  "exit" : "/d/wiz/demoroom.c",
])

*/




int check_quest(int type){

	object room2, *rewardee, quester;
	int done,d_bonus,reward,ret;
	
	room2 = this_object();
	if (!room2->query("entry_room"))	return 0;

	type = room2->query("maze/type");
	
	// Each Bandit counts as + 100% quest reward
	d_bonus = room2->query("maze/npc_killed")>= (9+type) ? (9+type): room2->query("maze/npc_killed");
	d_bonus = d_bonus*100;
	
	// There surely is a leader who counts as 120.
	d_bonus += 150 * room2->query("maze/leader_killed");
	
	switch (type) {
		case 2: d_bonus = d_bonus* 13/10; break;	// 增加 30% reward
		case 3: d_bonus = d_bonus* 17/10; break;	// 增加 70% reward	
		default:	break;
	}
		
	rewardee = get_players();
	if (!rewardee)	return 1;	// 没人领赏，不会吧。
	quester = find_player(owner);
	if (!quester) {
		tell_object(this_player(),HIR"由于领任务的人逃之夭夭，现在无法奖励，还是等他回来吧。\n"NOR);
//		room2->query("maze/sig")->refresh_maze();	// 摧毁 Maze
		return 1;
	}	// 我们不要求迷宫主人在迷宫里，但必须在线，以便于处理。
	
	environment(this_player())->set("burned",1);	// 防止出错
	
	CHANNEL_D->do_sys_channel("sys",sprintf("Maze type %d, quester is %O, blocker killed %d, leader killed %d,ppl inside %O. d_bonus is calculated to be %d \n", 
							room2->query("maze/type"),
							quester,
		 					room2->query("maze/npc_killed"),
		 					room2->query("maze/leader_killed"),
		 					rewardee,
		 					d_bonus ));
		
	QUESTS_D->dungeon_reward(quester, "垂笠老僧的任务", rewardee, d_bonus);
	ret=room2->query("fuben_event");
	SCHEDULE_D->delete_event(ret);
	FUBEN_D->clear_fuben("ultra",owner);		
	return 1;	
}
int do_get1(string arg){
	
	string arg1;
	int num,gao;
	object ye;
	
	if (!ye=present("bandit",this_object())) return 0;
	if (!arg)
		return 0;
		if (arg == "bao xiang" || arg == "宝箱" || arg == "baoxiang")		
	{
	
		tell_object(this_player(),ye->name()+"怒道：好大胆，竟然敢乱动老子的东西！\n");
		ye->kill_ob(this_player());
            return 1;
	}
	return 0;
}

int do_burn(){
	
	object ob,room2, me=this_player();
	int burned;
	
	if (ob=present("bandit",environment(me)) || ob=present ("bandit leader",environment(me))){
		tell_object(me,ob->name()+"说：你想干什么！\n");
		return notify_fail("");
	}
	else if (!environment(me)->query("burned"))
		{
			room2 = find_object("/f/ultra/"+owner+"/maze/entry");
			if (!room2){
				tell_object(me, "Error code dungeon 21230, please inform wiz\n");
				return 1;
			}
			room2->check_quest(1);
	} else
		tell_object(me,"这个地方已经被烧毁了。\n");	
	return 1;
}	

