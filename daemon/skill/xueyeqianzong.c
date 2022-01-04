inherit SKILL;

void setup(){
	set("name","雪野潜踪");
	set("practice_limit",100);
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",190);
	set("difficulty",200);
	set("skill_class","wolfmount");
	set("dodge_msg", ({
		"$n脚下游移不定，轻飘飘，不费力地闪在一旁。 \n",
		"$n用一种近似漂浮的动作滑开数步，躲开了$N的攻击。 \n",
		"$n侧身斜纵，远远跳开，同时回头紧盯$N招式的破绽。 \n",
		"$n左右闪动，迷惑了$N的视线，令$N的招式落空。 \n"
	}) );
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
