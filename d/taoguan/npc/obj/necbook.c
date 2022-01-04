inherit ITEM;
void create()
{
        set_name("三清道宗", ({ "necromancy_book" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","一本三清道教的镇教秘籍。");
                set("value", 0);
                set("no_stack", 1);
                set("material", "paper");
		    	set("is_xbook",1);
        }
    ::init_item();
}


void init()
{
  if(this_player()==environment())
  {
	set("no_get",1);
	set("no_give",1);
	  add_action("do_study","study");
  }
}
int do_study(string arg)
{
        object me,ob;
        int sena;
        int cps;
        string book;
        me = this_player();
        cps = random(({int})me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("指令格式：study 书 神数量\n");
        if( book != "necromancy_book")
                return notify_fail("你要读什麽？\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("你要读什麽？\n");
        tell_object(this_player(),"这书上的文字你看不懂耶，还是先学学「古篆」吧。\n");

        return 1;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

