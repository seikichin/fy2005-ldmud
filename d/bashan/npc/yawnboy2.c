#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("阿水", ({"sinny"}) );
        set("gender", "男性" );
        set("combat_exp", 10000000);
    	set("group","berserker");
        set("attitude", "peaceful");
    	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

    
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("sinny",300,220,1,"/obj/weapon/","fighter_w","spring-blade",4);
	setup();
	carry_object("/obj/weapon/dagger");
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
