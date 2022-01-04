           // Annie. 2005 
// Dancing_Faery@HOTMAIL.COM


#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	 object boss;
    
              FUBEN_D->enter_fuben(me, "ultra");
              boss = clone_object("/maze/ultra/npc/yaowang");
              boss->move(get_object("/f/ultra/"+me->query("id")+"/maze/exit"));
              get_object("/f/ultra/"+me->query("id")+"/maze")->set_display_map(1);
              get_object("/f/ultra/"+me->query("id")+"/maze")->set_maze_boss(boss);
              tell_object(me, "咦，这里好象有个隐蔽的迷宫，你撕下封条进入迷宫大门。\n");
              write("Ok.\n");
        return 1;
}