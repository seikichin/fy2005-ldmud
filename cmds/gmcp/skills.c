// say.c

#include <ansi.h>

inherit F_CLEAN_UP;
string *skill_level_desc = ({
	 "初学乍练" ,
	 "粗通皮毛" ,
	 "半生不熟" ,
	 "马马虎虎" ,
	 "驾轻就熟" ,
	 "出类拔萃" ,
	 "神乎其技" ,
	 "出神入化" ,
	 "登峰造极" ,
	 "一代宗师" ,
	 "深不可测" 
});

string *knowledge_level_desc = ({
	 "新学乍用" ,
	 "初窥门径" ,
	 "略知一二" ,
	 "马马虎虎" ,
	 "已有小成" ,
	 "心领神会" ,
	 "了然於胸" ,
	 "豁然贯通" ,
	 "举世无双" ,
	 "震古铄今" ,
	 "深不可测" 
});

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
	return "";
}

int main(object me, string arg)
{
   mapping  skl, lrn, map,tmp;
   string skill_;
   string *sname,*mapped;
   mixed *ska;
   int i;

	skl = this_player()->query_skills();
	if(!sizeof(skl)) {
		skill_="你目前并没有学会任何技能。\n";
		return 1;
	}
	skill_="你目前共学过"+chinese_number(sizeof(skl))+"种技能：\n\n";
	sname  = sort_array( keys(skl), #'> );
	ska=allocate(sizeof(sname));
	
	map = this_player()->query_skill_map();
	if( mappingp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn =this_player()->query_learned();
	if( !mappingp(lrn) ) lrn = ([]);
	
	for( i=0; i<sizeof(skl); i++) {
		if(!find_object(SKILL_D(sname[i])) && file_size(SKILL_D(sname[i])+".c")<0) 
		{
			this_player()->delete_skill(sname[i]);
			continue;
		}
		tmp=([
		"name":sprintf("%s%-30s-",
		(member_array(sname[i], mapped)==-1? "  ": "＊"),
		SKILL_D(sname[i])->name() + " (" + sname[i] + ")"),
		"rank":skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		"percent":sprintf("%3d/%1d",skl[sname[i]],({int})lrn[sname[i]]),
		"skill":sprintf("%s%-30s-",(member_array(sname[i], mapped)==-1? "  ": "＊"),
		SKILL_D(sname[i])->name() + " (" + sname[i] + ")")
		]);
		ska[i]=tmp;

	}
    this_player()->process_gmcp(ska,"Char.Training","List");
	return 1;
}
