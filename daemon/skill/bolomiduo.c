// bolomiduo.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","婆萝蜜多心经");
	set("type","force");
	set("effective_level",120);
	set("usage/force",1);
	set("difficulty",200);
	set("skill_class","lama");
}


//	明尊护体

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	
	if(!me->query_temp("pfm/dz_roar") || me->query("class")!= "lama"
		|| me->query_skill_mapped("iron-cloth")!= "jin-gang")
		return 0;
	
	data["msg"] = BRED + HIY"$n周身霞霓环绕，光华夺目，$N的攻势尽皆消逝！\n"NOR,
	data["damage"] = -damage;	// In Roar, we set resistance/kee = 100, so damage here is irrelevant.
	return data;	
}

int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
