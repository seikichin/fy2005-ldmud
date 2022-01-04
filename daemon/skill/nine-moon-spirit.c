// begging.c

inherit SKILL;

void setup() {
	set("name","姹女神功");
	set("effective_level",200);
	set("type","knowledge");
	set("skill_class","shenshui");
	set("no_refund", ({"nine-moon-sword","nine-moon-claw" }));
	set("difficulty",200);
	set("no_refund",({"qingpingforce","qingpingsword","chaos-steps"}));
}


int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	if(({string})me->query("class") != "shenshui" ) 
		return notify_fail("姹女神功是神水宫弟子独有的武功。\n");
	return 1;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
