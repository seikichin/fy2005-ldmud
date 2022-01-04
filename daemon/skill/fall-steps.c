/*【秋风辞】Fall-steps

秋风起兮白云飞，草木黄落兮雁南归。
兰有秀兮菊有芳，怀佳人兮不能忘。
汎楼船兮济汾河，横中流兮扬素波。
箫鼓鸣兮发棹歌，欢乐极兮哀情多，少壮几时兮奈老何。

*/

inherit SKILL;

void setup()
{
	set("name","秋风步法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","legend");
	set("dodge_msg", ({
		"$n一招「秋风起兮白云飞」轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「草木黄落兮雁南归」早已避在七尺之外。\n",
		"$n使出「兰有秀兮菊有芳」，轻轻松松地闪过。\n",
		"$n左足一点，一招「怀佳人兮不能忘」腾空而起，避了开去。\n",
		"可是$n使一招「泛楼船兮济汾河」，身子轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「横中流兮扬素波」轻轻闪过。\n",
		"但是$n一招「箫鼓鸣兮发棹歌」使出，早已绕到$N身後！\n",
		"但是$n身形飘忽，轻轻一纵，一招「欢乐极兮哀情多」，避开这一击。\n",
		"$n身形往上一拔，一招「少壮几时兮奈老何」，一个转折落在数尺之外。\n",
	}) );
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
