#include <ansi.h>
#include <command.h>
inherit NPC;
int qijiao();

void create()
{
        set_name("当班差役", ({ "chaiyi"}) );
        set("long", "正在当班的差役，负责给官老爷们备轿。(jiaozi)\n");
        set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("reward_npc", 1);
	set("difficulty", 5);

        set("cor", 40);
        set("cps", 25);

        set("combat_exp", 4000000);

	set("inquiry", ([
        	"轿子" : 	(: qijiao() :),
             	"jiaozi" : 	(: qijiao() :),
              	"jiao zi" : 	(: qijiao() :),
   	]));

        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
	set_skill("fumostaff",200);
	set_skill("meihua-shou",150);
	set_skill("puti-steps",200);
	
	map_skill("dodge","puti-steps");
	map_skill("staff","fumostaff");
	map_skill("unarmed","meihua-shou");
	map_skill("parry","fumostaff");
	
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}

int qijiao() {
	object me;
	string jiaozi;
	me=this_player();
	if (me->query("class")!="official") {
		command("say 你是什么人？有什么资格坐官轿？");
		return 1;
	}
	if (me->query("family/master_id")=="master yue") {
		message_vision("$N诚惶诚恐地对$n说：“小的这儿的官轿是给文官大人备的，将军还是骑马吧。”\n",this_object(),me);
		return 1;
	}
	if (me->is_fighting()) {
		message_vision("$N说：“大人还有事儿没处理完吧？”\n",this_object());
		return 1;
	}
	
	if (me->query("combat_exp")>5000000) jiaozi=HIG"绿呢"+HIY"金顶大轿"NOR;
		else if (me->query("combat_exp")>2500000) jiaozi=RED"红枣木大轿"NOR;
		else jiaozi=BLU"红漆黑顶蓝呢轿子"NOR;	
		
	message_vision("四个轿夫抬着一顶"+jiaozi+"走了过来。\n",this_object());
	message_vision("$N坐进轿子，$n高声吆喝：“"+me->name()+"大人起驾喽！”\n",me,this_object());
	me->start_busy(4);
	call_out("go_out_1",2,me,jiaozi);
	return 1;
}

int go_out_1(object me,string jiaozi) {
	object room;
	if (me->is_ghost()||me->is_fighting()) return 1;
	room=find_object(AREA_FY"fysquare");
	if(!objectp(room)) 
        	room = load_object(AREA_FY"fysquare");
        me->move(room);
        message_vision("$N坐着"+jiaozi+"走了过来。\n",me); 
        call_out("go_out_2",2,me,jiaozi);
        return 1;
}

int go_out_2(object me,string jiaozi) {
	object room;
	if (me->is_ghost()||me->is_fighting()) return 1;
	room=find_object(AREA_QUICKSAND"greenland");
	if(!objectp(room)) 
        	room = load_object(AREA_QUICKSAND"greenland");
        message_vision("$N坐着"+jiaozi+"向西离开。\n",me);
        me->move(room);
        message_vision("$N坐着"+jiaozi+"走了过来。\n",me); 
        call_out("go_out_3",2,me,jiaozi);
        return 1;
}

int go_out_3(object me,string jiaozi) {
	object room;
	if (me->is_ghost()||me->is_fighting()) return 1;
	message_vision("$N坐着"+jiaozi+"向西离开。\n",me);
	room=find_object(AREA_CHENXIANG"yam");
	if(!objectp(room)) 
        	room = load_object(AREA_CHENXIANG"yam");
        message_vision("$N坐着"+jiaozi+"走了过来。\n",me); 
         me->move(room);
        message_vision("$N拍了拍官服，走出轿子。\n",me);
        return 1;
}
