#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIG"上古妖王"NOR, ({"yao wang", "yao", "wang"}) );
        set("gender", "男性" );
        set("age", random(30)+20);
        set("long", "上古妖王,刚从封印中逃脱出。\n");
        set("attitude", "aggressive");
        set("class", "lvlin");
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("max_kee", 50000);
        set("max_gin", 50000);
        set("force", 150000);
        set("max_force", 50000);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 30);
        set("combat_exp", 500000);
        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("blade", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set("auto_perform", 1);

        setup();

}


