// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(BLK"插花石"NOR , ({ "ikebana stone","stone"}) );
	set_weight(50);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("unit", "颗");
        set("long", "一颗散发出神秘气息的的插花软石，这石材很奇怪，似乎可以布置一下ＡＲＲＡＮＧＥ。\n");
        set("value", 500000);
        set("lore",1);
	}
	::init_item();
}


void init()
{
  if(this_player()==environment())
  add_action("do_arrange","arrange");
}

int do_arrange()
{
	int i,begonia=0,gardenia=0,daisy=0,lily=0,hyacinth=0,snowlotus,skillslv=0;
	object jade,me, *inv;
	object begoniai,gardeniai,daisyi,lilyi,hyacinthi,snowlotusi;
	me = this_player();
	if (me->query("bellicosity")>0) {
		message_vision("$N杀气太高，似乎对插花这样的艺术理解不深。。。\n",this_player());
		return 1;
		}
	if (me->query_skill("zen") < 50) {
		message_vision("$N对禅道的理解还不够深，跟谈不上插花了。。。\n",this_player());
		return 1;
	}
	inv = all_inventory(me);
	        for(i=0; i<sizeof(inv); i++)
                {
                	if(inv[i]->query("name") == HIG"雏菊"NOR) {daisy = 1; daisyi = inv[i];}
                  if(inv[i]->query("name") == HIC"百合花"NOR) {lily = 1; lilyi = inv[i];}
                  if(inv[i]->query("name") == HIY"秋海棠"NOR) {begonia = 1; begoniai = inv[i];}
                  if(inv[i]->query("name") == HIW"栀子花"NOR) {gardenia = 1;  gardeniai = inv[i];}
                  if(inv[i]->query("name") == HIB"风信子"NOR) {hyacinth = 1;  hyacinthi = inv[i];}
                  if(inv[i]->query("name") == HIC"天山雪莲"NOR) {snowlotus = 1;  snowlotusi = inv[i];}
                  if(me->query_skill("zen")>=50) {skillslv = 1;}
		}
	if( daisyi && gardeniai && begoniai && lilyi && hyacinthi && snowlotusi && skillslv)
	{
			destruct(begoniai);
	        destruct(daisyi);
	        destruct(lilyi);
	        destruct(gardeniai);
	        destruct(hyacinthi);
	        destruct(snowlotusi);
			jade = clone_object(BOOKS"skill/xiaodao_75");
			jade->move(me);
			message_vision(HIG"$N手里的六朵花按照顺序摆放在插花石上，突然一道白光从天而降，回神过来时$N看着手中出现的奇迹激动不已。\n"NOR,this_player());
			
			if (!REWARD_D->riddle_check(me,"孝感苍天"))
				REWARD_D->riddle_set(me,"孝感苍天",1);

			REWARD_D->riddle_done( this_player(),"孝女花", 30, 1);
			destruct(this_object());
	
	}
	else 
		message_vision("$N把手里的几朵小花随意的摆放了一下，似乎缺少某些花。\n",this_player());
	return 1;
}

