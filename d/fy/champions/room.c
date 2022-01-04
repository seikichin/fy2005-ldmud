#include <ansi.h>
inherit ROOM;
string discribe(){
string cl;
mapping tm=(["yinshi":WHT "\n"
"\n"
"　　　　　　天庭近日缘花少　忽忆人间遇王孙\n"
"\n"
""
NOR   ,
"wudang":WHT "\n"
"\n"
"　　　　　　 几回问卜敲天地　\n"
"\n"
"　　　一次求签定苍茫\n"
"\n"
""
NOR,
	"wolfmount":WHT "\n"
"\n"
"　　　逢君若问儿时志　莫道凄然挂吴钩……\n"
"\n"
""
NOR,
	"taoist":WHT "\n"
"　　\n"
"　　　　　　 不爱长生天地短　\n"
"\n"
"　　　古今看罢有谁哭\n"
"\n"
""
NOR,
	"shenshui":WHT "\n"
"\n"
"　　　谁家玉笛凄声怨，扰乱禅心月分明？\n"
"\n"
""
NOR,
	"shaolin":WHT "\n"
"\n"
"　　　　　　 诸法空相皆自在　\n"
"\n"
"\n"
"　　　　　　　　　　拈花一笑任平生\n"
"\n"
""
NOR,
	"official":HIR"\n"
"\n"
"　　天兵照雪下玉关，\n"
"　　　　虏箭如沙射金甲\n"
"　云龙风虎尽交回，\n"
"　　　太白入月敌可摧\n"
"\n"
""
NOR ,
	"moon": WHT "\n"
"\n"
"　　　　　　 难料清秋十五夜　\n"
"\n"
"　　　安然沧海遍植桑\n"
"\n"
""
NOR,
	"legend":WHT "\n"
"\n"
"　　　　　　 斗酒设谜拼刀法　　\n"
"\n"
"　　　衣影飞扬隐庐巅\n"
"\n"
"\n"
""
NOR,
	"knight":WHT "\n"
"　\n"
"\n"
"　　　　　　 四海翻腾云水怒　\n"
"\n"
"　　　九洲震荡风雷激\n"
"\n"
""
NOR,
	"huashan": WHT "\n"
"\n"
"　　　　　　　　　　万里浮云卷碧山，青天中道流孤月。\n"
"　　　孤月沧浪河汉清，北斗错落长庚明。 \n"
"　　　　　　　怀余对酒夜霜白，玉床金井水峥嵘。人生飘忽百年内， \n"
"　　　　　　　　　　　且须酣畅万古情。\n"
"\n"
""
NOR ,
	"bonze":WHT "\n"
"\n"
"　　　　　　 无奈失题说弦管　\n"
"\n"
"　　　尘缘旧事亦消磨\n"
"\n"
""
NOR,
	"beggar":WHT "\n"
"\n"
"　　　　　　无端最是家乡曲\n"
"\n"
"　　　　　　　　　　骤起堂前人半痴\n"
"\n"
""
NOR ,
	"bat":WHT "\n\n"
"　　　　　　百花发时我不发，我花发时百花杀。\n"
"	    待到秋来九月八，我花开后百花杀。 \n"
"	    冲天香阵透长安，满城尽带黄金甲。\n"
"\n"
""
NOR,
	"assassin":WHT "\n"
"\n"
"　　　　　　既然要走，就不该来;\n"
"\n"
"　　　　　　　　　　既然来了，又何必走?\n"
"\n"
""
NOR ,
	"fugui":WHT "\n"
"\n"
"　　　　　　 借问流年几易逝　\n"
"　\n"
"　　　帘外西风舞狂颠\n"
"\n"
"\n"
""
NOR,
	]);


cl=this_player()->query("class");
cl=tm[cl];
if(cl) return cl;

return WHT "\n"
"\n"
"　　　　　　 且把金尊倾美酿　\n"
"　\n"
"　　　休思往事成惆怅\n"
"\n"
"\n"
"";
}
void create()
{
  set ("short", HIY"镜之回廊"NOR);

   set("long",(:discribe():));
    set("exits", ([ 
	"down" : "/d/fy/mirrorgallery",
      ]));

  	set("objects",([
	/*__DIR__"npc/"+query("class") : 1,*/
	]));


	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
	set("coor/z",20);
    set("map","fynorth");
    setup();
}







/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/

