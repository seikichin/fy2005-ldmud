
inherit ROOM;

void create()
{
    set("short", "张家铁铺");
    set("long","风云老少都喜欢在这里打造称手的铁器，从火炉中冒出的火光将墙壁映得通红，\n"
"屋子的角落里堆满了各式铁器，锄头、铁锤、铲子、长剑等，有的已经完工，有的\n"
"还只是个粗模，叮叮当当打铁的声音满屋子响。门口有一个大木牌（ｓｉｇｎ）。\n"
);
    set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"huanyun8",
      ]));

    set("objects", ([
	__DIR__"npc/smith": 1 ]) );
    set("item_desc", ([
	"sign": "\n"
"[0;1;37m────────────────────────────────[0m\n"
"[0;1;36m		本铁铺提供业务[0m\n"
"[0;1;37m────────────────────────────────[0m\n"
"\n"
"（1）修补武器（ｘｉｕ）：\n"
"* 自制武器每点一两黄金．但不会超过武器伤害力的四分之一。\n"
"* 非自制武器，伤害力25以下统收一两黄金，25以上每点三两黄金。\n"
"\n"
"（2）估价（ｅｓｔｉｍａｔｅ）\n"
"估算修理武器所需要的金额。\n"
"\n"
"（3）订作自制武器（ｄｉｎｇ）：每件十两黄金\n"
"\n"
"斧（ａｘｅ），刀（ｂｌａｄｅ），锤（ｈａｍｍｅｒ），\n"
"矛（ｓｐｅａｒ），杖（ｓｔａｆｆ），剑（ｓｗｏｒｄ），\n"
"鞭（ｗｈｉｐ）\n"
"\n"
"ｄｉｎｇ <武器种类> <颜色> <武器中文名> <武器英文名>\n"
"\n"
"例子：\n"
"ｄｉｎｇ　ｓｗｏｒｄ　$ＨＩＧ$ 碧血剑 ｂｌｏｏｄｙ\n"
"\n"
"张铁匠就会用他自备的材料帮你作一件发绿色的＂碧血剑＂ \n"
"叫 ｂｌｏｏｄｙ\n"
"\n"
"$BLK$ - 黑色            $NOR$ - 恢复正常颜色\n"
"$RED$ - 红色            $HIR$ - 亮红色\n"
"$GRN$ - 绿色            $HIG$ - 亮绿色\n"
"$YEL$ - 土黄色          $HIY$ - 黄色\n"
"$BLU$ - 深蓝色          $HIB$ - 蓝色\n"
"$MAG$ - 浅紫色          $HIM$ - 粉红色\n"
"$CYN$ - 蓝绿色          $HIC$ - 天青色\n"
"$WHT$ - 浅灰色          $HIW$ - 白色\n"
"\n"
"＊具体颜色可用命令color察看。\n"
"＊自制武器成功后无法改变中英文代号或武器种类，请慎重选择。\n"
"＊自制武器命名请注意\n"
"（１）不要采用人名、或通俗物名如sword等为英文名，\n"
"否则可能导致你无法正常看到该物品的信息。\n"
"（２）不要采用不雅名字，否则巫师将将其销毁并不作赔偿。\n"
"\n"
"＊与以往风云版本不同，铸剑不再需要自备原料，提高武器杀伤\n"
"力的途径为寻找各种原料，而后到祭剑亭的樊夫人处祭剑。最基\n"
"本的祭剑原料可在嵩山脚下孙记铁铺处购买，以后便会从谜题或\n"
"杀死NPC后得到，新手也可向老玩家购买。但是，许多原料都有\n"
"一定的等级要求，只有达到这一等级才能祭剑。\n"
"\n"
"＊自制武器后可用alter命令来改变佩戴信息。\n"
"\n"
"＊自制武器可用destroy销毁，注意，武器上所有属性等也会被毁。\n"
"\n"
"[0;1;37m────────────────────────────────[0m\n"
""
      ]) );

    set("coor/x",40);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
