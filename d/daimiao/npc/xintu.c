inherit NPC;
#include <ansi.h>

void create()
{
	set_name("阿大", ({ "a da"}) );
	set("gender", "男性" );
	set("age", 35);
	
	set("long","此人自称是东岳大帝的门人，也许有些真功夫。\n"
""
);

	set("title",HIC"东一气"NOR);
	set("attitude", "peaceful");
        set("combat_exp", 500000);

        set_skill("unarmed", 100);
        set_skill("yiqiforce", 30);
        set_skill("force", 100);
        set_skill("iron-cloth",200);
        
        map_skill("iron-cloth","yiqiforce");
	map_skill("unarmed", "yiqiforce");
    
        set("chat_chance", 1);
        set("chat_msg", ({
             "阿大说：有了混元一气功，老子就是天下第一了。\n",
        }) );

	setup();
        carry_object("/obj/armor/cloth")->wear();
 
}
