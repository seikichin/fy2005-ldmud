
#include <ansi.h>
#include <weapon.h>

inherit FORK; 

void create()
{
        set_name(  "叉" , ({ "fork" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把普普通通的叉，从上到下没有任何起眼之处。\n"
);
                set("material", "steel");
                set("rigidity", 100000);
                set("weapon_prop/agility", 2);
                set("weapon_prop/intelligence", 1);
                set("weapon_prop/courage", 1);
                set("weapon_prop/composure", 1);
        }

        ::init_fork(20);
}
 
void init()
{
	add_action("do_make","remake");
}


int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=clone_object(__DIR__"commcase");
	obj->move(me);
        if(query("equipped")) unequip();
        tell_object(me,"你将手中的"+query("name")+"又拆开，组成个箱子。\n");
        destruct(this_object());
	return 1;
}          
  
