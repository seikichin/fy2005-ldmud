#include <ansi.h>
inherit NPC;

void create()
{
    set_name("小媳妇儿", ({ "just-married" }) );
    set("gender", "女性");
    set("age", 18);
    set("per", 40);
    set("long","一个愁眉苦脸的小媳妇儿，虽然一身村姑打扮，透着水灵劲儿。\n");
    set("combat_exp",5000);

    set("chat_chance", 1);
    set("chat_msg", ({
	"小媳妇儿说：我这日子过的跟守寡似的，可怎么办呀。\n",
	"小媳妇儿说：谁能把我家那口子劝回家，小女子天天为他烧香。\n"
      }) );

    set("inquiry", ([
	"难事": "我家那口子练武练邪了，这三天两头地连家都不沾边。。。。好好的田不种，却在庄稼地里抓麻雀练什么天罗地网功。\n",
	"守寡": "我家那口子练武练邪了，这三天两头地连家都不沾边。。。。好好的田不种，却在庄稼地里抓麻雀练什么天罗地网功。\n",
	"我家那口子": "我家那口子练武练邪了，这三天两头地连家都不沾边。。。。好好的田不种，却在庄稼地里抓麻雀练什么天罗地网功。\n",
	"大汉": "我家那口子练武练邪了，这三天两头地连家都不沾边。。。。好好的田不种，却在庄稼地里抓麻雀练什么天罗地网功。\n",
	"老公": "我家那口子练武练邪了，这三天两头地连家都不沾边。。。。好好的田不种，却在庄稼地里抓麻雀练什么天罗地网功。\n",
	"丈夫": "我家那口子练武练邪了，这三天两头地连家都不沾边。。。。好好的田不种，却在庄稼地里抓麻雀练什么天罗地网功。\n",
    "铁剑":	"咳，那口子说，他的功夫已经高的不需要真刀真剑了。\n",
      ]) );

    setup();	
    carry_object("/obj/armor/cloth")->wear();
}

