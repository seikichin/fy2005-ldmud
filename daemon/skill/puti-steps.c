//TIE@FY3
// puti-steps.c

inherit SKILL;
void setup(){
	set("name","菩提虚空步法");
	set("skill_class","shaolin");
	set("type","step");
	set("effective_level",140);
	set("usage/dodge",1);
	set("usage/move",1);
	set("practice_limit",100);
	set("difficulty",200);

	set("dodge_msg", ({
		"$n一招「菩提本无树」轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「灵镜亦非台」早已避在七尺之外。\n",
		"$n使出「本来无一物」，轻轻松松地闪过。\n",
		"$n左足一点，一招「何处惹尘埃」腾空而起，避了开去。\n",
		"可是$n使一招「身化曹溪水」，身子轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「滔滔遍九垓」轻轻闪过。\n",
		"但是$n一招「行时步步有」使出，早已绕到$N身後！\n",
	        "但是$n身形飘忽，轻轻一纵，一招「说来句句空」，避开这一击。\n",
	        "$n身形往上一拔，一招「辗转费疑猜」，一个转折落在数尺之外。\n",

	}) );
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
