#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("花紫藤", ({ "gate keeper","keeper" }) );
	set("title",YEL"大光明教"CYN" 右门神"NOR);
	set("nickname",HIB"地"HIR"缺"NOR);
	set("gender", "女性");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("reward_npc", 1);
	set("difficulty", 1);

	set("combat_exp", 8000000);
	set("chat_chance", 0);
	set("chat_msg", ({
	"花紫藤说道：开门？先用你的血来祭过门神。\n",
	}) );

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","mixed_demon",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(MAG"妖魂法袍"NOR, ({ "unholy robe","robe"}) );
	weapon->set("long","妖魂法袍(Unholy robr)。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon=carry_object("/obj/weapon/blade");
	weapon=carry_object("/obj/weapon/whip");
	weapon=carry_object(__DIR__"obj/wolfclaw");
	weapon->set_name(BLU"残缺铁爪"NOR, ({ "claw"}) );
	weapon->set("long","残缺铁爪(Claw)。\n");
	weapon->set("value",0);
	weapon->wield();

}
/*
void kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return ;
}
*/
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
