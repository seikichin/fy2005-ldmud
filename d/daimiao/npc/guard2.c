#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("灰狼弟子", ({ "huilang dizi", "dizi"}) );
        set("title",WHT"西方神教 "NOR);
        set("gender", "男性" );
        set("group","demon");
        set("age", 22);
        set("long","西方神教复现江湖，天地人三长老，四金刚，金银铜铁锡五护卫。\n"
"又分白鸽、灰狼、黄犬，三个分舵。“黄犬”负责追踪：“灰狼”\n"
"负责搏杀：“白鸽”的任务，就是负责刺探传递各路的消息。\n");
        set("combat_exp", 2300000);
        set("attitude", "friendly");
                        
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
     }) ); 		

	
	auto_npc_setup("wang",170,140,1,"/obj/weapon/","fighter_w","assassin-hammer",1);
	setup();
	carry_object("/obj/armor/cloth",([	
    						"name":  "灰色教服",
    						"long": "西方神教教众的服饰。\n",
    						 ]))->wear();
}
