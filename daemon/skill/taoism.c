// taoism.c

inherit SKILL;
void setup(){
	set("name","天师正道");
	set("skill_class","taoist");
	set("usage/literate",1);
	set("type","knowledge");
	set("effective_level",200);
	set("difficulty",250);
	set("no_refund",({"necromancy","scratmancy","gouyee"}));
}

int valid_learn(object me) 
{
        if(me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼天师正道。\n");
        return 1;
}


int help(object me)
{
	write(funcall(#'read_file,"/help/skills/"+__FILE__[14..<3]));
    return 1;
}
