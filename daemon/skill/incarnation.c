// incarnation.c

inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","修仙术");
	set("type","knowledge");
	set("skill_class","basic");
	set("difficulty",100);
	set("usage/literate",1);
	set("bounce_ratio",10);
	set("effective_level",50);
	set("difficutly", 200);	
		set("absorb_msg", ({
	        "$n运起先天罡气，脸部神态，居然发出了一种隐约的淡金色的光辉。\n",
	        "$n不避不闪，身畔推出一道狂飙，既纯且柔，正是武当派“先天无上罡气”。\n",
	}) );

}


void skill_improved(object me)
{
    	int s;

    	s = me->query_skill("incarnation", 1);
	if ( s == 220 && me->query("class") == "wudang")
		tell_object(me,HIY"由于你苦修修仙之术，你的先天无上罡气已初勘门径。\n");
			
/*    	if( s%10==9 && ({int})me->query("spi") < s/5) {
        	tell_object(me, HIW "由於你勤练修仙术，你的灵性提高了。\n" NOR);
        	me->set("spi",(s+1)/5);
    	}*/
}

int skill_difficulty() {
	
	int skill;
	if (this_player()) {
		skill = this_player()->query_skill("incarnation",1);
		if (skill<=200) return 200;
	}
	return skill*3;	
}


int valid_enable(string usage) 
{ 
	object me;
	if (me=this_player())
		if(me->query_skill("incarnation",1)>=220){
			return usage=="literate"||usage=="iron-cloth"; 
	}
	else
		return usage=="literate";
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
