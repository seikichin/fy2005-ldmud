// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;

mapping area_name = ([ 
		"baiyun"	:	"白云城",
		"bat"		:	"蝙蝠岛",
		"bashan"	: 	"巴山",
		"bawang"	:	"饿虎岗",
		"biancheng"	:	"边城",
		"cave"		:   "风云地下城",
		"chenxiang"	:	"沉香镇",
		"chuenyu"	:	"黑松堡",
		"cyan"		: 	"明霞山",
		"daimiao"	:	"岱庙",
		"death"		:	"鬼门关",
		"eastcoast"	: 	"东海",
		"eren"		:    "恶人谷",
		"eren2"		:    "恶人谷",
		"fy"		:	"风云城",
		"fugui"		:    "富贵山庄",
		"fycycle"	:  	"风云城",
		"fywall"	:   "风云城",
		"ghost"		:    "幽灵山庄",
		"guanwai"	:  	"关外",
		"guanyin"	:  	"天枫",
		"huangshan"	:	"黄山",
		"huashan"	:  	"华山",
		"jinan"		:    "济南",
		"laowu"		:    "老屋",
		"libie"		:    "无名小镇",
		"loulan"	:   "楼兰",
		"manglin"	:  	"莽林",
		"oldpine"	:  	"老松寨",
		"palace"	:   "帝王谷",
		"qianfo"	:   "千佛山",
		"qianjin"	:  	"千金楼",
		"qingping"	: 	"清平山庄",
		"quicksand"	:	"大沙漠",
		"resort"	:   "铁雪山庄",
		"shaolin"	:  	"少林寺",
		"shenshui"	: 	"神水宫",
		"songshan"	: 	"嵩山",
		"taiping"	:  	"太平镇",
		"taishan"	:  	"泰山",
		"taoguan"	:  	"桃源",
		"taoyuan"	:  	"三清观",
		"tieflag"	:  	"大旗谷",
		"wanmei"	:   "万梅山庄",
		"wolfmount"	:	"狼山",
		"wudang"	:   "武当",
		"xiangsi"	: 	"相思岭",
		"xinjiang"	: 	"新疆",
		"yingou"	:   "银钩赌坊",
		"zhaoze"	:	"沼泽地",
		"zangbei"	:	"藏北",
]);                             

int main(object me, string arg)
{                               
	object ob, man;
	int i, cost;            
	object room;            
	string location,*area,line;
                         
    if (me->query("NO_PK"))
		return notify_fail("此命令只有巡捕和逃犯才能使用。\n");
	
	if ( !arg )             
		return notify_fail("你要暗中调查谁的消息？\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要打听谁的消息？\n");
	if ( ob == me )         
		return notify_fail("睁大眼睛看看自己吧！\n");

	if (ob->query("NO_PK"))
		return notify_fail("此命令只有针对巡捕或者逃犯使用。\n");
		
    if ( present(ob, environment(me)) )
        return notify_fail("这个人就在你眼前！\n");

	if ( me->query("sen") <= 500 )
		return notify_fail("此命令至少耗费500点心神。\n");
	me->receive_damage("sen", 500);		

	room=environment(ob);
	area=keys(area_name);
	if (!room) 
		write("不清楚在哪里可以找到"+ob->name()+"。\n");
	else {
		location=domain_file(file_name(room));
		if (member_array(location,area)==-1)	
			write("不清楚在哪里可以找到"+ob->name()+"。\n");
		else 
			write(ob->name()+"好像最近经常在"+area_name[location]+"一带走动。\n");
			
	}
	me -> perform_busy(1);
	return 1;
}


int help(object me)
{
	write("[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m指令格式 : 	pklocate <某人>[0m\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
"此命令为卷入江湖仇杀的玩家专用，可以大致确定其他卷入江湖仇杀的\n"
"玩家的所在地区。\n"
"\n"
"[0;1;37m────────────────────────────────[0m   \n"
"\n"
);
    return 1;
}
