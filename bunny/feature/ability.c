// Silencer @ FY4 workgroup. Oct.2004
#include <ansi.h>
#define MAX_EXPERTISE 100
#define MAX_MEMORIZED 3
	
string *g_ability = ({
		"strength",
		"intelligence",
		"agility",
		"composure",
		"karma",
		"constitution",
		"kee",
		"gin",
		"sen",
		"force",
		"mana",
		"atman",
		"dodge",
		"parry",
		"no_busy",
	});
string *g_ability_info = ({
		"力量值提高１点\t\t","才智值提高１点\t\t","速度值提高１点\t\t",
		"定力值提高１点\t\t","运气值提高１点\t\t","体质值提高１点\t\t",
		"气血值提高１００点\t","精力值提高１００点\t","心神值提高１００点\t",
		"内力值提高５０点\t","法力值提高５０点\t","魔力值提高５０点\t",
		"直接闪避机会增加１％\t","直接招架机会增加１％\t",
		"流转真气机会增加0.5％\t",
	});

mapping g_ability_pot = ([
		"dodge":	2,
		"parry":	2,
		"no_busy":	3,
]);

/* ABILITY2

str/int/comp/agi/karma/con
mana/force/atman
gin/kee/sen

shaolin: con, composure, karma, kee/gin/sen 100+
lama: con, composure, karma, kee/gin/sen 100+
legend: con, composure, karma, kee/gin/sen 100+

taoist/yinshi: int, karma, agi, mana/force/atman 50+

huashan/bonze: comp, int, con, mana/force/atman 50+

officer/beggar/wolfmount/moon/knight/fugui agi, str, karma, mana/force/atman 50+

*/

mapping m_ability3 = ([
// tank
	"lama":({"karma", "composure", "constitution", "kee", "force", "dodge", "no_busy", "3_fengmo_add", "3_an_add", "3_ma_add"}),
	"legend":({"karma", "composure", "agility", "kee", "force", "dodge", "3_wuye_add", "3_luoye_add", "3_wuzhanmei_add", "3_zhongliu_add"}),
	"shaolin":({"karma", "composure", "constitution", "kee", "force", "parry", "3_yzc_add", "3_xuanji_add", "3_foguan_add", "3_weapon_add"}),

// caster
	"taoist":({"intelligence", "karma", "agility", "atman", "mana", "force", "3_bolt1_add", "3_bolt2_add", "3_heal_add", "3_guard_add"}),
	"yinshi":({"intelligence", "karma", "agility", "dodge", "parry", "force", "3_yl9x_add", "3_bcurse_add", "3_spirit_add", "3_buffup_add"}),

// healer
	"huashan":({"agility", "composure", "constitution", "atman", "force", "parry", "3_d_duration", "3_d_damage", "3_huayu_add", "3_zhaixin_add"}),
	"bonze": ({ "intelligence", "composure", "constitution", "atman", "force", "parry", "3_zhuxian_add", "3_mind_add", "3_lxyy_add", "3_void_add"}),

// dps
	"knight":({"agility", "strength", "karma", "dodge", "parry", "force", "3_xiumu_add", "3_canyunbi_add", "3_longlife_add", "3_beisusan_add"}),
	"fugui": ({"agility", "strength", "karma", "dodge", "parry", "force", "3_erchuan_add", "3_cunjin_add", "3_lxgd_add", "3_xyxx_add"}),
	"wolfmount":({"agility", "strength", "karma", "dodge", "parry", "force", "3_wolf_add", "3_blyj_add", "3_shigu_add", "3_shexin_add"}),
	"beggar":({"agility", "strength", "karma", "dodge", "parry", "force", "3_gwxd_add", "3_pizi_add", "3_zjbl_dmg", "3_zjbl_brk"}),
	"official":({"agility", "strength", "karma", "dodge", "parry", "force", "3_zhtx_add", "3_array_add", "3_huwei_lvl", "3_huwei_pfm"}),
	"shenshui":({"agility", "strength", "karma", "dodge", "parry", "force", "3_huaxue_add", "3_slcx_add", "3_mihun_add", "3_polu_add"}),
	"moon":({"agility", "composure", "karma", "dodge", "parry", "force", "3_shnj_add", "3_thyx_add", "3_ltsc_add", "3_myqh_add"}),
	"assassin":({"agility", "strength", "karma", "dodge", "parry", "force", "3_mphl_add", "3_lfbj_add", "3_lfsf_add", "3_srrm_add"}),	
	]);
	
mapping m_ability3_info = ([
	"assassin": ({ 
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"麻婆寒练时间间隔减少30秒 ",
			"龙凤双飞暴击几率增加１％",
			"龙凤双飞伤害力提高5％\t",
			"杀人如麻双倍伤害几率增加10％",
			}),
	"lama": ({
			"运气值提高１点\t\t",
			"定力值提高１点\t\t",
			"体质值提高１点\t\t",
			"气血值提高１００点\t",
			"内力值提高５０点\t",
			"直接闪避机会增加０．５％",
			"流转真气机会增加１％\t",
			"『疯魔』的间隔减少３６秒",
			"『唵』杀伤力加倍几率＋２％",
			"『嘛』治疗加倍几率＋２％",
		}),

	"legend": ({
			"运气值提高１点\t\t",
			"定力值提高１点\t\t",
			"速度值提高１点\t\t",
			"气血值提高１００点\t",
			"内力值提高５０点\t",
			"直接闪避机会增加０．５％",
			"『舞叶』护甲＋５\t",
			"落叶秋风失败不受攻击＋１０％",
			"『五展梅』再次使用时间－３秒",
			"『中流』期间攻击力＋２０",
		}),

	"shaolin": ({
			"运气值提高１点\t\t",
			"定力值提高１点\t\t",
			"体质值提高１点\t\t",
			"气血值提高１００点\t",
			"内力值提高５０点\t",
			"直接招架机会增加０．５％",
			"一指禅伤害心神几率＋２％",
			"『玄机』有效时间增加６秒",
			"『佛光普照』有效时间增加２秒",
			"枪法／斧法伤害力增加２％",
		}),

	"taoist": ({
			"才智值提高１点\t\t",
			"运气值提高１点\t\t",
			"速度值提高１点\t\t",
			"魔力值提高５０点\t",
			"法力值提高５０点\t",
			"内力值提高５０点\t",
			"青冥苍灵紫幽杀伤力＋２％",
			"天罡燃殇御雷杀伤力＋２％",
			"复苏灵息带来的憎恨－５％",
			"天兵抵抗气血伤害＋１\t％",
		}),

	"yinshi": ({
			"才智值提高１点\t\t",
			"运气值提高１点\t\t",
			"速度值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"云龙九现无忙乱＋１％\t",
			"血降持续时间加倍＋１０％",
			"亡灵攻击时伤害力＋５％\t",
			"寒心诀增加精气神１００点",
		}),

	"huashan": ({
			"速度值提高１点\t\t",
			"定力值提高１点\t\t",
			"体质值提高１点\t\t",
			"魔力值提高５０点\t",
			"内力值提高５０点\t",
			"直接招架机会增加０．５％",
			"舞技时间延长２秒\t",
			"舞技增加附加伤害＋５\t",
			"+１％几率漫天花雨加倍\t",
			"摘心增加＋１０％气血伤害\t",
		}),

	"bonze": ({
			"才智值提高１点\t\t",
			"定力值提高１点\t\t",
			"体质值提高１点\t\t",
			"魔力值提高５０点\t",
			"内力值提高５０点\t",
			"直接招架机会增加０．５％",
			"诛仙诀伤害力增加２％\t",
			"神识伤害转化内力＋０．５％",
			"龙现于野额外攻击力＋３\t",
			"空识降低攻击和闪避＋５\t",
		}),

	"moon": ({
			"速度值提高１点\t\t",
			"定力值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"霜华凝结再次使用时间－１５秒",
			"天河一线忽略对手招架＋１０％",
			"连天衰草减少对手神防功效＋２％",
			"明月／清辉伤害力＋２％\t",
	}),

	"shenshui": ({
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"化血神功再次使用时间减少２０秒",
			"霜冷残霞第二击几率＋５％",
			"『迷魂术』伤害力增加１０％",
			"『破颅』第二击杀伤力增加＋３％",
		}),

	"official": ({
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"纵横天下＋１０％减少１轮忙乱",
			"阵法变换间隔减少０．４秒",
			"护卫提高１个等级\t",
			"护卫增加１％几率使用特技",
		}),

	"beggar": ({
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"狗尾续貂额外攻击的杀伤＋１５",
			"『缠／劈』几率增加＋０。５％",
			"震惊百里伤害力提高３％\t",
			"震惊百里＋５％几率不被中断",
		}),

	"wolfmount": ({
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"啸出的狼精气神增加３％\t",
			"搏浪一击＋２％几率不被中断",
			"『嗜骨』伤害力提高５％\t",
			"『摄心咒』有效时间增加2秒",
		}),

	"knight": ({ 
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"朽木功抵御气伤害增加１％",
			"残云碧暴击几率增加１％\t",
			"苍生诀贯通经脉几率增加１％",
			"悲酥散效果增加５％\t",
			}),

	"fugui": ({
			"速度值提高１点\t\t",
			"力量值提高１点\t\t",
			"运气值提高１点\t\t",
			"直接闪避机会增加０．５％",
			"直接招架机会增加０．５％",
			"内力值提高５０点\t",
			"『二串炮』双倍效果＋１０％",
			"『寸进』持续时间增加２秒",
			"『沥血肝胆』连击几率＋３％",
			"血雨潇潇双倍效果＋１０％",
		}),
	]);

mapping m_ability = ([
		"knight":({"poison_dmg", "poison_dur", "chunquye_amt", "resist_gin", "resist_sen"}),
		"taoist":({"nether_add", "feeble_add", "shangjun_add", "tianshi_add", "jisi_add"}),
		"lama":({"fuhu_add", "xianglong_add", "guanyin1_add", "guanyin2_add", "mz_add"}),
		"legend": ({"wuye_add", "jushen_add", "juli_add", "juxue_add", "parry_add"}),
		"huashan": ({"huayu_add", "huashang_add", "zhaixin_add", "heal_add", "xyqj_add"}),
		"fugui": ({"jswk_add", "erchuan_add", "lgss_add", "jybt_add", "plsg_add"}),
		"shaolin": ({"sanzang_add", "foguang_add", "qixing_add", "xuanfeng_add", "hefeng_add"}),
		"yinshi": ({"thunderwhip_add", "blood_add", "buffup_add", "yljx_add", "heal_add"}),
		"wolfmount": ({"xiao_add", "shigu_add", "paragon_add", "bolang1_add", "bolang2_add"}),
		"bonze": ({"avatar_add", "lightsense_add", "void_add", "heal1_add", "heal2_add"}),
		"beggar": ({"hunyuan_add", "pizi_add", "shuhu_add", "xianglong_add", "gouwei_add"}),
		"official": ({"shi_add", "jiu_add", "ba_add", "yi_add", "huwei_add" }),
		"shenshui": ({"jiasi_add", "wwdz_add", "wwdz2_add", "huaxue_add", "yrcy_add"}),
		"moon": ({"chillblade_add", "wfbh_add", "ylkm_add", "yzhs_add", "flfy_add",}),
	       "assassin": ({"sharen_add", "ruma_add", "clzx_add", "jjj_add", "mphl_add",}),
	]);

mapping m_ability_info = ([
		"assassin": ({
			"杀人如麻的增加系数＋１\t",
			"杀人如麻的使用时间减少加1秒",
			"苍龙乍现的时间增加２秒\t",
			"可以使用静行心法的聚神诀\t",
			"麻婆寒练术持续用时间增加1秒",
		}),
	"moon": ({
			"昆仑品雪的增加系数＋１\t",
			"无方变幻持续时间增加６秒",
			"阴陵扣命的时间增加２秒\t",
			"七星伴月的功效增加５％\t",
			"风漏飞烟＋１０％忽略对手招架",
		}),

	"shenshui": ({
			"假死的再次使用时间减少１分钟",
			"唯我独尊再次使用时间减少１分钟",
			"唯我独尊的伤害力提高＋５％",
			"提高化血神功的功效＋５％",
			"意染苍云再次使用时间减少６秒钟",
		}),

	"lama": ({
			"使用伏虎的间隔减少１２秒",
			"使用降龙的间隔减少２４秒",
			"『唵』的杀伤力增加＋３％",
			"『呢』的杀伤力增加＋３％",
			"使用明尊护身的间隔减少６０秒",
		}),

	"official": ({
			"十面埋伏中有效时间增加９秒钟",
			"九曜星宮再次使用时间减少１分钟",
			"八卦金锁再次使用时间减少１分钟",
			"一字长蛇再次使用时间减少１分钟",
			"护卫的气血值提高＋２％\t",
		}),

	"beggar": ({
			"『混元訣』功效增加＋５％",
			"『劈字诀』几率增加＋０。５％",
			"『倏忽訣』时间间隔减少３０秒",
			"『降龙无悔』聚力时间减少１秒",
			"『狗尾续貂』生效几率增加＋２％",
		}),

	"wolfmount": ({
			"『唤狼』的时间间隔减少１秒",
			"『嗜骨』的功效增加＋２％",
			"『天狼诀』的功效增加＋３％",
			"『搏浪七杀』杀伤加倍几率＋１％",
			"『搏浪七杀』刺杀的杀伤力＋２％",
		}),

	"knight": ({
			"残云碧玉肌凉的伤害力提高＋２％",
			"残云碧的持续时间延长＋５％",
			"春去也恢复几率增加２％/t",
			"朽木功抵御精／神伤害增加１％",
			"九气破霄＋１０％减少１轮忙乱",
		}),

	"taoist": ({
			"青冥燃殇杀伤力加倍几率＋２％",
			"苍灵紫幽杀伤力加倍几率＋２％",
			"上君的经验等级提高＋１％",
			"天师的经验等级提高＋１％",
			"无常的经验等级提高＋１％",
		}),

	"legend": ({
			"舞叶提高气血数增加１５０点",
			"使用聚神诀的间隔减少１２秒",
			"使用聚力诀的间隔减少１２秒",
			"使用聚血诀的间隔减少２分钟",
			"刀剑合击的招架几率增加１０％",
		}),

	"huashan": ({
			"+０.５％几率漫天花雨加倍",
			"化霜诀治愈效能增加＋３％",
			"摘心式再次使用时间减少１分钟",
			"+１％几率治愈特技不耗费内力",
			"心有千结自伤减少３％\t",
		}),

	"fugui": ({
			"金石为开的功效增加＋３％",
			"二串炮的使用间隔减少４５秒",
			"李广射石再次使用时间减少６秒",
			"饥鹰搏兔持续时间延长２秒",
			"蟠龙锁关再次使用时间减少１分钟",
		}),

	"shaolin": ({
			"使用三藏净身回复内力＋５％",
			"佛光普照再次使用时间减少３０秒",
			"七星夺魄再次使用时间减少２秒",
			"旋风斩再次使用时间减少２秒",
			"和风再次使用时间减少２０秒",
		}),

	"yinshi": ({
			"天雷鞭法杀伤力提高＋２％",
			"提高血降的杀伤力＋３％\t",
			"提高寒心诀的加血功效＋５％",
			"提高云龙九现的杀伤力＋２％",
			"提高乾坤愈的治疗功效＋５％",
		}),

	"bonze": ({
			"日月光佛增加属性＋１\t",
			"光识杀伤力增加＋２％\t",
			"空识持续时间延长１秒\t",
			"疗伤恢复气血值＋２％\t",
			"疗伤＋１％几率恢复加倍\t",
		}),
	]);

mapping pfm_r1_data = ([
	"tiandirenmojue": ([ // 与八方风雨类似，enable 500 vs enable 550
		"e_id":	"tiandirenmo",
		"c_id":	"天地人魔",
		"owner":	"master figure",
		"answer":	"$N面纱下的双眼忽然精光湛闪，$N说：你竟能寻到此物，神教不会亏待于你。\n",
		"fixed_atk":	530,	// Enable = 500
		"fixed_dmg":	710,	// str = 95
		"self_busy":	3,
		"cdt":			300,	// individual_cdt
		"g_cdt":		60,		// global_cdt
		"weapon":		1,
		]),

	"jichulianhuanjue": ([ // 3%*8
		"e_id":	"jichulianhuan",
		"c_id":	"计出连环",
		"owner":	"xie zhanggui",
		"answer":	"$N脸色微微一变，笑了笑说，神剑山庄，正是收藏此宝之地，多谢这位侠士。\n",
		"fixed_atk":	500,	// Enable = 500
		"fixed_dmg":	710,	// str = 70
		"self_busy":	3,
		"cdt":			300,	// individual_cdt
		"g_cdt":		60,		// global_cdt
		"weapon":		1,
		]),

	"tianwaifeixianjue": ([
		"e_id":	"tianwanfeixian",
		"c_id":	"天外飞仙",
		"owner":	"master ye",
		"answer":	"$N微捻长髯，长笑道：不错，他日得登大宝，汝当也有一份功劳。\n",
		"fixed_atk":	500,
		"fixed_dmg":	710,
		"self_busy":	3,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		1,
		]),

	"luorijue": ([
		"e_id":	"luori",
		"c_id":	"长河落日",
		"owner":	"master chu",
		"answer":	"$N长叹道：古来英雄多寂寞……一个人在低处时，总想往高处走。\n",
		"fixed_atk":	550,
		"fixed_dmg":	910,
		"self_busy":	2,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"hantianjue": ([
		"e_id":	"hantian",
		"c_id":	"寒天神掌",
		"owner":	"master ximen",
		"answer":	"$N冷冷道：据说碰过这本书的人，一个个都死了，我倒要试试看。\n",
		"fixed_atk":	700,
		"fixed_dmg":	1500,
		"self_busy":	1,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"miwujue": ([
		"e_id":	"miwu",
		"c_id":	"十里迷雾",
		"owner":	"master li",
		"answer":	"$N兴高采烈地说道：没想到我竟得此宝籍，真是我门之幸，夫人之福！\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	1,
		"cdt":			180,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"soulflamejue": ([
		"e_id":	"soulflame",
		"c_id":	"魔火炼魂",
		"owner":	"yi ku",
		"answer":	"$N喜道：待我练成这宝籍，还会怕阿飞那根破铁片！\n",
		"fixed_atk":	800,
		"fixed_dmg":	1000,
		"self_busy":	2,
		"cdt":			180,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"jixingjue": ([
		"e_id":	"jixing",
		"c_id":	"射月击星",
		"owner":	"master shi",
		"answer":	"$N喜道：有这宝籍，我武当功夫必然更上一层楼！\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	0,
		"cdt":			180,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"jiemaijue": ([
		"e_id":	"jiemai",
		"c_id":	"点血截脉",
		"owner":	"wan chunliu",
		"answer":	"$N笑道：拿这残鉴来换我的医术，怕还是你得益的多。\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	1,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),

	"mengyanjue": ([
		"e_id":	"mengyan",
		"c_id":	"梦魇召唤",
		"owner":	"master ding",
		"answer":	"$N点头道：虽说此非道教正籍，我且收下。\n",
		"fixed_atk":	500,
		"fixed_dmg":	1000,
		"self_busy":	1,
		"cdt":			300,
		"g_cdt":		60,
		"weapon":		0,
		]),
	]);

int deduct_ability_cost(object ob, string arg, int flag);
int check_ability(object me,string arg, int flag);
int improve_ability(object me,string arg, int flag);
int check_ability_improve(object me, string arg, int flag);
string get_ability_idf(object me,string arg, int flag);
string get_ability_info(object ob, string arg, int flag);

// L80-120.每10级可以多学两点，所以最早Ｌ120可以学到一个Ｌ１０
int check_ability_improve(object me, string arg, int flag)
{
	int level, a_lvl;
	level = F_LEVEL->get_level(me->query("combat_exp"));
	a_lvl = check_ability(me, arg, flag);
	if( a_lvl >= 10 ) {
		return 0;
	}
	if( flag == 0 && level < 80 ) {
		return 0;
	}
	if( flag == 1 && level < 100 ) {
		return 0;
	}
	if( flag == 3 ) {
		if( level < 40 ) {
			return 0;
		}
		if( (level-40)/10 + 1 > a_lvl ) {
			return 1;
		} else {
			return 0;
		}
	}
	if( (level-80)/5 + 1 > a_lvl ) {
		return 1;
	}
	return 0;
}

varargs int check_ability(object me,string arg, int flag)
{
	int level, result;
	
	// Although we have defined NPC ability here, 
	// what really matter are only dodge/parry/menpai abilities, 
	// att are useless since we don't actually add them to NPC
	if( !userp(me) && !me->query("possessed") ) {
		if( flag == 3 ) {
			// disable NPC ability3
			return 0;
		} else {
			level = F_LEVEL->get_level(me->query("combat_exp"));
			if( level < 80 ) {
				return 0;
			}
			if( level > 150) {
				return 14;
			}
			return (level-80)/5;
		}
	}
	
	if( flag == 3) {
		// Ability3 TASK		
		result = me->query("ability3/"+ me->query("class")+ "/"+ arg);
	} else {
		// Ability 门派
		result = me->query("ability2/"+ me->query("class")+ "/"+ arg) + me->query("ability/"+arg);
	}
	return result;
}

int check_ability_cost(object me, string arg, int flag) 
{
	int cost;

	if( flag == 1 ) {
		cost = 2;
	} else if( flag == 3 ) {
		cost = 1;
	} else {
		if( member_array(arg, g_ability) == -1 ) {
			return 0;
		}
		cost = g_ability_pot[arg];
		if( !cost ) {
			cost = 1;
		}
	}
	return cost;
}


// 每次耗费一点能力点
int deduct_ability_cost(object me, string arg, int flag)
{
	int lvl, cost;
	int n;
	int total_count, saved_book, saved_task, saved_count, saved_ability3, learned_ability3;
	lvl = check_ability(me, arg, flag);
	cost = check_ability_cost(me, arg, flag);
	
	if (flag == 1 || flag == 0) {
		if( cost > me->query("saved_quest")/60/100 - me->query("learned_ability") ) {
			return 0;
		}
		me->add("learned_ability", cost);
	}
	
	if( flag == 3 ) {
		n = 300;
		total_count = me->query("TASK");
		saved_book = me->query("marks/book_task");
		saved_task = total_count - saved_book;
		saved_count = saved_task + saved_book/2;
		saved_ability3 = saved_count/n;
		learned_ability3 = me->query("learned_ability3");
		if( cost > saved_ability3 - learned_ability3 ) {
			return 0;
		}
		me->add("learned_ability3", cost);
	}
	
	return 1;
}

int improve_ability(object me,string arg, int flag)
{
//	int lv;
	string myclass;

	myclass = me->query("class");
	if( !flag ) {
		me->add("ability/"+arg,1);
		switch (arg) {
			case "strength":
				{
					me->add("str",1);
					break;
				}
			case "intelligence":
				{
					me->add("int",1);
					break;
				}
			case "composure":
				{
					me->add("cps",1);
					break;
				}
			case "karma":
				{
					me->add("kar",1);
					break;
				}
			case "agility":
				{
					me->add("agi",1);
					break;
				}
			case "constitution":
				{
					me->add("con",1);
					break;
				}
			case "mana":
				{
					me->add("Add_mana/ability",50);
					me->add("max_mana",50);
					break;
				}
			case "atman":
				{
					me->add("Add_atman/ability",50);
					me->add("max_atman",50);
					break;
				}
			case "force":
				{
					me->add("Add_force/ability",50); 
					me->add("max_force",50);
					break;
				}
			case "kee":
				{
					me->add("max_kee",100);
					break;
				}
			case "gin":
				{
					me->add("max_gin",100);
					break;
				}
			case "sen":
				{
					me->add("max_sen",100);
					break;
				}
			case "parry": // in combatd.c
			case "dodge": // in combatd.c
			case "no_busy": // in action.c
				{
					break;
				}
		}
	} else if( flag == 1 ) {
		me->add("ability2/"+myclass+"/"+arg,1);
	} else if( flag == 3 ) {
		me->add("ability3/"+ myclass + "/" + arg,1);
		switch (arg) {
			case "strength":
				{
					me->add("str",1);
					break;
				}
			case "intelligence":
				{
					me->add("int",1);
					break;
				}
			case "composure":
				{
					me->add("cps",1);
					break;
				}
			case "karma":
				{
					me->add("kar",1);
					break;
				}
			case "agility":
				{
					me->add("agi",1);
					break;
				}
			case "constitution":
				{
					me->add("con",1);
					break;
				}
			case "mana":
				{
					me->add("Add_mana_only/ability3",50);	
					me->add("max_mana",50);
					break;
				}
			case "atman":
				{
					me->add("Add_atman_only/ability3",50);
					me->add("max_atman",50);
					break;
				}
			case "force":
				{
					me->add("Add_force_only/ability3",50); 
					me->add("max_force",50);
					break;
				}
			case "kee":
				{
					me->add("max_kee",100);
					break;
				}
			case "gin":
				{
					me->add("max_gin",100);
					break;
				}
			case "sen":
				{
					me->add("max_sen",100);
					break;
				}
			case "parry": // in combatd.c
			case "dodge": // in combatd.c
			case "no_busy": // in action.c
				{
					break;
				}
		}
	}
	return 1;
}

string get_ability_info(object ob, string arg, int flag)
{
	int lv, cost, n;
	string desc, msg, myclass;

	lv = check_ability(ob, arg, flag);
	cost = check_ability_cost(ob, arg, flag);
	desc = get_ability_idf(ob,arg,flag);
	if( flag == 1 ) {
		// ability's 门派技能
		myclass = ob->query("class");
		if( pointerp(m_ability[myclass]) ) {
			n = member_array(arg,m_ability[myclass]);
			if( n != -1 ) {
				msg = m_ability_info[myclass][n];
				msg = sprintf(msg+"\t%-10s\t%3d\n",desc, cost);
				return msg;
			}
		}
		return "";
	}
	if( flag == 3) {
		// ability3
		myclass = ob->query("class");
		if( pointerp(m_ability3[myclass]) ) {
			n = member_array(arg,m_ability3[myclass]);
			if( n != -1 ) {
				msg = m_ability3_info[myclass][n];
				msg = sprintf(msg+"\t%-10s\t%3d\n",desc, cost);
				return msg;
			}
		}
		return "";
	}
	n = member_array(arg, g_ability);
	if( n != -1 ) {
		msg = g_ability_info[n];
		msg = sprintf(msg+"\t%-10s\t%3d\n", desc, cost);
		return msg;
	}
	return "";
}


string get_ability_idf(object me,string arg, int flag)
{
	int lev = check_ability(me,arg,flag);
	// 1,2,3,4 Basic
	// 5,6,7 Advanced
	// 8,9: Master
	// 10: Grand Master
	string *tough_level_desc = ({
		YEL "一无所知" NOR,//0
		HIB "初窥门径" NOR,//1
		HIB "略知一二" NOR,//2
		HIB "粗通皮毛" NOR,//3
		HIB "马马虎虎" NOR,//4
		CYN "了然於胸" NOR,//5
		CYN "出类拔萃" NOR,//6
		CYN "登峰造极" NOR,//7
		HIC "一代宗师" NOR,//8
		HIC "举世无双" NOR,//9
		HIW "深不可测" NOR,//10
		HIW "深不可测" NOR,//11 - These are just for some NPC setup
		HIW "深不可测" NOR,//12
		HIW "深不可测" NOR,//13
		HIW "深不可测" NOR,//14
		HIW "深不可测" NOR,//15
		HIW "深不可测" NOR,//16
		HIW "深不可测" NOR,//17
		HIW "深不可测" NOR,//18
		HIW "深不可测" NOR,//19
		HIW "深不可测" NOR,//20
	});
	return (tough_level_desc[lev]+"（"+ lev +"）");
}

mapping	reward_perform_1(string p_name)
{
//	CHANNEL_D->do_sys_channel("sys",sprintf("perform data returned is %O. \n", pfm_r1_data[p_name]));
	return pfm_r1_data[p_name];
}

mapping query_pfm_r1()
{
	return pfm_r1_data;
}

int check_pfm_r1(object who, string p_name)
{
	mapping perform;
	int duration, duration1,duration2;
	perform = pfm_r1_data[p_name];
	if( F_LEVEL->get_level(who->query("combat_exp")) < 100 ) {
		tell_object(who,"使用风云绝技需要等级100以上。\n");
		return 0;
	}
	if( !who->query_weapon() && perform["weapon"] ) {
		tell_object(who,"使用此心诀必须持有武器。\n");
		return 0;
	}
	if( who->query_weapon() && !perform["weapon"] ) {
		tell_object(who,"使用此心诀必须空手。\n");
		return 0;
	}
	// Low level has a 30mins CDT, so it's a one short boost
	if( F_LEVEL->get_level(who->query("combat_exp")) < 100 ) {
		duration = who->query("timer/pfm/pfm_r1") + 1800 - time();
		if( duration > 0 ) {
			tell_object(who,"你心力交瘁，还需要等待"+(duration/60)+"分钟才能再次使用风云绝技。\n");
			return 0;
		}
	}
	if( who->query("pfm_r1/"+p_name+"/expertise") < MAX_EXPERTISE && who->query("pfm_r1/"+p_name+"/memorized") < 1 ) {
		tell_object(who,"你还没有熟练掌握『"+perform["c_id"]+"』，无法随心使用。\n");
		return 0;
	}
	duration1 = who->query("timer/pfm/pfm_r1") + perform["g_cdt"] - time();
	if( duration1 > 0 ) {
		tell_object(who,"你还要需要等待"+duration1+"秒才能使用叱咤风云之特技。\n");
	}
	duration2 = who->query("timer/pfm/"+p_name) + perform["cdt"] - time();
	if( duration2 > 0 ) {
		tell_object(who,"你还要需要等待"+duration2+"秒才能使用『"+perform["c_id"]+"心诀』\n");
	}
	if( duration1 > 0 || duration2 > 0 ) {
		return 0;
	}
	return 1;
}

int add_pfm_r1_expertise(object who, string p_name, int i)
{
	if( who->query("pfm_r1/"+p_name +"/expertise") == 24 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s（%s）的『%s』心诀已经初窥门径了。\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name +"/expertise") == 49 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s（%s）的『%s』心诀已经马马虎虎了。\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name +"/expertise") == 74 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s（%s）的『%s』心诀已经出类拔萃了。\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name +"/expertise") == 99 ) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s（%s）的『%s』心诀已经深不可测了。\n", 
		who->name(1),who->query("id"),pfm_r1_data[p_name]["c_id"]));
	}
	if( who->query("pfm_r1/"+p_name+"/expertise")+i <= MAX_EXPERTISE ) {
		who->add("pfm_r1/"+p_name+"/expertise",i);
	} else {
		who->set("pfm_r1/"+p_name+"/expertise",MAX_EXPERTISE);
	}
	return 1;
}
	
int add_pfm_r1_memorized(object who, string p_name, int i)
{
	if( who->query("pfm_r1/"+p_name+"/memorized")+i <= MAX_MEMORIZED ) {
		who->add("pfm_r1/"+p_name+"/memorized",i);
	} else {
		who->set("pfm_r1/"+p_name+"/memorized",MAX_MEMORIZED);
	}
	if( who->query("pfm_r1/"+p_name+"/memorized") < 0 ) {
		who->set("pfm_r1/"+p_name+"/memorized",0);
	}
	return 1;
}

int pfm_r1_book_reward(object me, object who, object obj)
{
	int i, n, num;
	string* pfm_name;
//	CHANNEL_D->do_sys_channel("sys"," checking books\n");
	if( !obj->query("pfm_r1") ) {
		return 0;
	}
	num = sizeof(pfm_r1_data);
	pfm_name = keys(pfm_r1_data);
	n = 999;
	for( i = 0; i < num; i++) {
//		CHANNEL_D->do_sys_channel("sys", sprintf("%d master is %s\n", i, pfm_r1_data[pfm_name[i]]["owner"]));
		if( pfm_r1_data[pfm_name[i]]["owner"] == who->query("id") ) {
			n = i;
			break;
		}
	}
//	CHANNEL_D->do_sys_channel("sys"," i ="+i+"\n");
	if( n == 999 ) {
		return 0;
	}
	if( me->query("pfm_r1/"+pfm_name[i]+"/expertise")+me->query("pfm_r1/"+pfm_name[i]+"/memorized") >= MAX_EXPERTISE ) {
		tell_object(me,who->name()+"微微一笑道：你对此心法的了解已经不输与我了。\n");
		return 0;
	}
	if( me->query("pfm_r1/"+pfm_name[i]+"/memorized") >= MAX_MEMORIZED ) {
		tell_object(me,who->name()+"摇摇头说：我早已收阅此页。\n");
		return 0;
	}
	message_vision(pfm_r1_data[pfm_name[n]]["answer"], who, me);
	tell_object(me,YEL+who->name()+"说：你天赋异廪，我且指点你几招。\n"+who->name()+"在你耳边低声说了几句。\n"NOR);
	tell_object(me,YEL"你似乎懂得了一些『"+pfm_r1_data[pfm_name[n]]["c_id"]+"』的心诀。\n"NOR);
	add_pfm_r1_memorized(me,pfm_name[n],1);
	if( obj ) {
		destruct(obj);
	}
	return 1;
}