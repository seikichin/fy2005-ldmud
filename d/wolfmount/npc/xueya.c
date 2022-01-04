#include <ansi.h>
inherit NPC;

void create()
{
	set_name("血牙", ({"xueya"}) );
        set("gender", "男性" );
        set("nickname", HIR"噬人狼"NOR);
        set("long", "这是一个嗜血如命，凶狠残忍的食人狼弟子。\n");
 	set("attitude", "friendly");
/*	set("max_gin", 600);
	set("max_kee", 600);
	set("max_sen", 600);  */
	set("age", 20+random(10));
        set("combat_exp", random(500000)+600000);

        create_family("狼山", 4, "弟子");
        set_skill("blade", 70+random(10));
        set_skill("parry", 70+random(10));
        set_skill("dodge", 70+random(10));
        set_skill("move", 70+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
		"血牙舔了舔嘴唇：好几天都没吃到新鲜的人肉了！\n",
        }) );

        setup();
     	carry_object(__DIR__"obj/pifeng")->wear();
		carry_object(__DIR__"obj/wolfblade")->wield(); 
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if (!ob || environment(ob)!= environment(this_object()))	return;
	if(ob->query("class") != "wolfmount")
	{
		message_vision("$N舔了舔舌头，笑道：“好一头肥羊啊，肯定是疯了，居然敢上狼山。”\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
      	}
      	return;
}
