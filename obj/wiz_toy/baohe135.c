#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "宝盒" NOR, ({ "bao he" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "iron");
            set("long", "一个宝盒。\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me,ob;
        me = this_player();
        if(arg != "bao he" && arg != "宝盒") return 0;
        if(query("opened"))
                return notify_fail("你打开宝盒，但里面是空的！\n");
         ob=clone_object("/obj/generate/wrists_170_9.c");
        ob->move(this_player());
        ob=clone_object("/obj/generate/surcoat_170_22.c");
         ob->move(this_player());
       ob=clone_object("/obj/generate/neck_170_20.c");
        ob->move(this_player());
       ob=clone_object("/obj/generate/head_170_21.c");
       ob->move(this_player());
      ob=clone_object("/obj/generate/boots_170_11.c");
       ob->move(this_player());
       ob=clone_object("/obj/generate/surcoat_170_12.c");
        ob->move(this_player());
       ob=clone_object("/obj/generate/neck_170_10.c");
        ob->move(this_player());
       ob=clone_object("/obj/generate/head_170_10.c");
        ob->move(this_player());
       ob=clone_object("/obj/generate/cloth2_170_10.c");
        ob->move(this_player());
       ob=clone_object("/obj/generate/cloth2_170_20.c");
        ob->move(this_player());
       ob=clone_object("/obj/generate/boots_170_21.c");
        ob->move(this_player());
         me->add("potential",20000);
       message_vision(HIR "\n$N打开宝盒，两眼发光，好多装备啊！\n\n" NOR,me);
       set("opened",1);
        return 1;
}
