// mind_bug.c

inherit NPC;

void create()
{
        set_name("观想虫", ({ "mind bug", "bug" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", 
"这是一只由修道人的杂念绮思所化的观想虫，会缠住人的魂魄。\n");
        
        set("str", 24);
        set("cor", 26);

        set("max_kee", 140);
        set("max_gin", 250);
        set("max_sen", 600);

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        
        if( this_player() ) {
                set("combat_exp", ({int})this_player()->query_skill("spells", 
1) * 500);
                set("bellicosity", this_player()->query("bellicosity"));
        }

        set_temp("apply/attack", 30);
        set_temp("apply/armor", 10);

        setup();
}

void die()
{
        string owner;
        object owner_ob, killer, rkiller;

        owner = query("owner");
	if(stringp(owner))
        if( objectp(owner_ob = find_player(owner)) ) {
		killer = ({object})query_temp("last_damage_from");
	        if(!objectp(rkiller=killer->query("possessed"))) rkiller = killer ;
                if( (killer != owner_ob) && (rkiller != owner_ob)) {
                        tell_object(owner_ob, 
"你的观想虫被人杀死了！\n你觉得一阵天旋地转....\n");
                        owner_ob->unconcious();
		} else if (owner_ob->query_skill("spells",1)<=200) {
			tell_object(owner_ob, "你杀死了你的观想虫，并且从中悟到了一些咒术的道理。\n");
			owner_ob->improve_skill("spells", random(owner_ob->query("spi")/2)+1);
		} else tell_object(owner_ob,"你杀死了你的观想兽，但是你的咒术已经不能由此提高了。\n");
        }
        ::die();
}
 
