#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short","阁老池");
  set("long","眼前就是阁老池，石栏环筑，小巧玲珑。在池内及其周围分布着九块玲珑石，\n"
"是金代大安元年，奉符县吴刊奉老母王氏所献，姿态古怪，耐人寻味。更怪的是在\n"
"阁老池的东侧有两棵"YEL"古柏"NOR"，一棵树干上淤结了一个球状疤瘤，另一棵已经枯死。\n"
);
  	set("exits",([
         	"north":__DIR__"zhengyuan",
         	"south":__DIR__"renan",
        ]));
        set("objects", ([
                __DIR__"npc/ren" : 1,
                __DIR__"npc/daoshi" : 1,
        ]) );
        set("item_desc", ([
        	"古柏":"\n"
"在阁老池的东侧有古柏，树干上淤结了一个球状疤瘤，酷似一只双目仰视的\n"
"瑞兽麒麟，右上方还有一个圆形树疤，天然的组成了岱庙八景之一的『麒麟\n"
"望月』。\n"
"池之北侧路东又有一株枯死的古柏，躯体以顺时针方向拧扭盘旋而上，纹理\n"
"清晰，质感细腻，尤为奇特。传说它是一位古代忠臣的化身，在陪同天子祭\n"
"泰山时，由于不满巨大的耗资而挡驾进谏，激怒了天子，后在群臣的请求下\n"
"虽免于一死，但又因他的耿直不阿，拒不谢罪而重被斩首，他的魂魄就立于\n"
"路旁向泰山神申冤告状，被列为岱庙八景之一『宁死不屈』。\n",
        	"柏":"\n"
"在阁老池的东侧有古柏，树干上淤结了一个球状疤瘤，酷似一只双目仰视的\n"
"瑞兽麒麟，右上方还有一个圆形树疤，天然的组成了岱庙八景之一的『麒麟\n"
"望月』。\n"
"池之北侧路东又有一株枯死的古柏，躯体以顺时针方向拧扭盘旋而上，纹理\n"
"清晰，质感细腻，尤为奇特。传说它是一位古代忠臣的化身，在陪同天子祭\n"
"泰山时，由于不满巨大的耗资而挡驾进谏，激怒了天子，后在群臣的请求下\n"
"虽免于一死，但又因他的耿直不阿，拒不谢罪而重被斩首，他的魂魄就立于\n"
"路旁向泰山神申冤告状，被列为岱庙八景之一『宁死不屈』。\n",        	        
		"tree":"\n"
"在阁老池的东侧有古柏，树干上淤结了一个球状疤瘤，酷似一只双目仰视的\n"
"瑞兽麒麟，右上方还有一个圆形树疤，天然的组成了岱庙八景之一的『麒麟\n"
"望月』。\n"
"池之北侧路东又有一株枯死的古柏，躯体以顺时针方向拧扭盘旋而上，纹理\n"
"清晰，质感细腻，尤为奇特。传说它是一位古代忠臣的化身，在陪同天子祭\n"
"泰山时，由于不满巨大的耗资而挡驾进谏，激怒了天子，后在群臣的请求下\n"
"虽免于一死，但又因他的耿直不阿，拒不谢罪而重被斩首，他的魂魄就立于\n"
"路旁向泰山神申冤告状，被列为岱庙八景之一『宁死不屈』。\n",        	        
        ]) );
	set("coor/x",0);
	set("coor/y",-25);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

