#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"新手指南"NOR, ({"book" }));
	set_weight(1);
	set("unit", "本");
	set("no_split", 1);
   	set("long", "\n"
"怎样提高自己的精气神？风云人物由精力，气血，和心神三\n"
"个主要数值，灵力，内力和法力三个次要数值来代表其状态\n"
"。灵力、内力、法力越高，对应的精力、气血、心神越长，\n"
"在战斗中就越不容易死亡，越不容易到塔祝那儿喝茶。　　\n\n"
"法术（ｍａｇｉｃ）可以提高灵力；内功（ｆｏｒｃｅ）\n"
"可以提高内力；学习咒术（ｓｐｅｌｌｓ）可以提高法力。\n\n"
"基础的武功入门书籍可以在风云城及第街读千里处买到，\n"
"识字就能学。学到一些法术、内功、咒术后就可以想法提高\n"
"灵力、内力、法力了，有几种途径：\n\n"
"１。打坐练功（ｈｅｌｐ ｅｘｅｒｃｉｓｅ）,收效甚慢。\n\n"
"２。在风云城的天骄门吐纳练功ｔｕｎａ，系统将自动计算\n"
"你的精气神值（相当于再次登陆）\n\n"
"３。每次重新登录时将自动计算各项数值。\n\n"
"（如果你不是机器自虐狂人，强烈推荐方法２）\n\n"
);
	set("value", 1);
	::init_item();
}

