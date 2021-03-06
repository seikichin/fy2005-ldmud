// painting

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("名画", ({ "painting"}) );
	set_weight(1);
	if( clonep() )
    	set_default_object(__FILE__);
	else {
    	set("long", "一幅名画\n");
    	set("unit", "幅");
    	set("value", 2);
	}
	::init_item();
}

mapping *painting= ({
	([	"name":HIC"万壑松风图"NOR,
		"author":"李唐",
		"long":"画上是插云的尖峰，斧凿般的冈峦，峭壁，山腰的白云冉冉欲动。满山都是葱\n"
"郁的松林，一条飞瀑辗转垂下，形成穿石的涧水，这正是宋人李唐的名画“万\n"
"壑松风图”。\n"
"",
	]),
	([	"name":HIG"溪山清远图"NOR,
		"author":"夏王圭",
		"long":"邱壑澄江，时而危峰突起，时而悠然远眺，山川萦带，坡陀僧宇。笔墨紧密松\n"
"秀，景物布列得宜。正是一幅宋人夏王圭的名画“溪山清远图”。\n"
"",
	]),
	([	"name":HIB"华灯侍宴图"NOR,
		"author":"马远",
		"long":"暮色下的华屋里正点着彩灯，举行盛宴。远处群山矗立，摇摆的松枝凸现着暮\n"
"色苍茫，正是一幅宋人马远的名画“华灯侍宴图”。\n"
"",
	]),
	([	"name":HIW"临流独坐图"NOR,
		"author":"无名氏",
		"long":"近景临河岩石上大树六株，有枯枝，有夹叶式点叶树，前后交错，团聚成林。\n"
"背后道路以木桥连接右岸。另一边坡岸上，有茅舍水榭，前倾弯曲的老树下，\n"
"坐一文士，眺望空阔无际的河水。其后两群山石相背，山上也生长着屈干丛木。\n"
"右侧一山，林隙中露出茅舍一角，溪涧自山谷间涌出。两山间以缓坡山径相连，\n"
"隔着一层云雾，又有两山耸峙，山体更大，而山顶远树则缩为细点。山谷蒸岚，\n"
"树木楼阁只露出顶端，右侧悬岩深处瀑布直下。主山自两峰间迎面耸立，主宰\n"
"整个山川的形势。正是一幅无名氏的名画“临流独坐图”。\n"
"",
	]),
	([	"name":HIY"松亭会友图"NOR,
		"author":"王渊",
		"long":"双松苍秀挺拔，造型古朴稳健,临水茅亭，内有文士二位，一人倚栏坐看仆从搬\n"
"运食盒，一人远眺江面水阔天空。崖前舣舟，近水操渡，天外帆樯，随风远飙，\n"
"全幅景致清远幽静，笔墨清逸秀雅，画面气氛安逸，正是一幅元人王渊的名画\n"
"“松亭会友图”。\n"
"",
	]),
	([	"name":CYN"元世祖出猎图"NOR,
		"author":"刘贯道",
		"long":"画幅甚大，画北方沙漠之地，黄沙浩瀚，一望无垠。人骑数众，中骑黑马衣着白\n"
"裘者，为元世祖。与世祖并辔衣白袍者为帝后。余男女八骑，皆是其侍从。或弯\n"
"弓、或架鹰、或纵犬、或携猎豹。上方远处沙丘之外，有驼队一列，缓缓而行。\n"
"完全描写塞外大漠打猎之景。正是一幅元人刘贯道的“元世祖出猎图”。\n"
"",
	]),
});

			
			

mapping query_paint()
{
	return painting[random(sizeof(painting))];
}