
#include <skill.h>
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int research_limit(object me, string skill)
{
	string myclass;
	int nlimit;

	if( skill == "shortsong-blade" || skill == "diesword") {
		nlimit = 260;
	} else if( skill == "chillblade" ) {
		nlimit = 240;
	} else {
		myclass = me->query("class");
		me->set("class", SKILL_D(skill)->skill_class());
		nlimit = 450 * 100 / SKILL_D(skill)->effective_level(me);
		nlimit = (nlimit / 5 + 1) * 5;
		if( myclass ) {
			me->set("class", myclass);
		} else {
			me->delete("class");
		}
	}
	return (nlimit >= 400 ? 400 : nlimit);
}

int main(object me, string arg)
{
	string skill, check;
	int nlimit;
	int my_skill_level;
	int pot, amount;

	if( me->is_fighting() ) {
		return notify_fail("在战斗中搞研究？\n");
	}

	if ( !arg ) {
		return notify_fail("指令格式: research 技能 with 潜能点数\n");
	}

	if( sscanf(arg, "%s with %d", skill, pot) != 2 ) {
		if( sscanf(arg, "%s with %s", skill, check) == 2 ) {
			if ( check == "limit" ) {
				my_skill_level = ({int})me->query_skill(skill, 1);
				if( !my_skill_level ) {
        			return notify_fail("你对此项技能一无所知，如何搞研究？\n");
				}
    			nlimit = research_limit(me, skill);
				tell_object( me, "此项技能能够钻研到的最高等级为"+ nlimit +"。\n");
				return 1;
				}
		}
		return notify_fail("指令格式: research <技能> with <潜能点数>\n");
	}

	my_skill_level = ({int})me->query_skill(skill, 1);
	if( !my_skill_level ) {
		return notify_fail("你对此项技能一无所知，如何搞研究？\n");
	}

	if( !SKILL_D(skill)->valid_learn(me) ) {
		return 0;
	}

	nlimit = research_limit(me, skill);
	if( my_skill_level >= nlimit ) {
		return notify_fail("虽然你苦心钻研，但是若非另有奇遇，已经无法进一步领悟此项技能了。\n");
	}
	if( pot < 100 ) {
		 return notify_fail("这点潜能不够用来做研究（至少需用100点）\n");
	}
	if( pot > 10000 ) {
		return notify_fail("为防止溢出，每次用于研究的潜能不能超过１００００点。\n");
	}
	if( pot > ({int})me->query("potential") - ({int})me->query("learned_points") ) {
		 return notify_fail("你的潜能点不够！\n");
	}

	if( me->query_int() <= 40 ) {
		amount = (400 + 30 * me->query_int()) * 2 * pot;
	} else {
		amount = to_int((pow(to_float(me->query_int()*10), 0.03) * 871 - 950) * 173 / 5 * pot);
	}

	if( me->query("national") == "苗族" ) {	
		amount = amount + amount/20;		// 民族特性
	}
	amount = amount / SKILL_D(skill)->skill_difficulty();

	//	以上实际上就是直接学习此项技能的效率，对于研究来说，/5
	amount = amount / 5;	            	

	write("你对"+SKILL_D(skill)->name()+"作了一番彻底的研究！（+" +amount +"）\n");
	me->add("learned_points", pot);
	me->add("annie/skill_cost/"+skill, pot);
	me->research_skill(skill, amount);
	return 1;
}
            	
            	
int help(object me)
{
	write( "\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	research <技能> with <潜能点数>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"风云中共有四种获取技能的途径：	读书（study）\n"
"				学习（learn）\n"
"				[1;31m钻研（research）[0m\n"
"				练习（practice）\n"
"\n"
"当你成长到一定程度，会发现自己已经学会了所有师傅能传授的技能，\n"
"当然你仍然可以遍历各地，寻访新的师傅或者武功秘籍，风云里有足够\n"
"的东西可学。但另一方面，你也可以利用自己的才智阅历，对已学会的\n"
"功夫进一步钻研。钻研是一种自我领悟和飞跃的过程，难度要比向师傅\n"
"学要大得多，不过唯有这样，你才能超越前人，成为一代宗师。\n"
"\n"
"这一指令让你用指定的潜能对某项技能作深入的研究。\n"
"一般来说，研究的难度是同样从师傅那儿学习此项的5倍。\n"
"更难的是，钻研需要升级的点数是学习的两倍，\n"
"\n"
"举例：\n"
"＊蝶恋花剑法 (diesword)                  - 粗通皮毛  22/  530\n"
"如果你向师傅学，花一点潜能立即能升为 23级。\n"
"如果你是自己钻研，需要成为\n"
"＊蝶恋花剑法 (diesword)                  - 粗通皮毛  22/  1060\n"
"后才能升到23级。\n"
"\n"
"钻研的效率与以下因素相关：\n"
"（1）才智：越聪明的人，用同样的潜能领悟到的技能就多。\n"
"（2）技能种类：不同的武功技能难度不同，最容易的是打基础的功夫。\n"
"（3）民族特性，苗族的钻研效率比较高。\n"
"\n"
"钻研的局限：人力有穷尽之时，当你的技能达到一定级别时，\n"
"（技能等级x系数>= 450)\n"
"若非再有奇缘，光靠个人的钻研就无法进一步提高了。\n"
"使用命令 Research <技能> with limit 可以查看你所拥有技能可达到\n"
"的最大等级。\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
""
	);
	return 1;
}

