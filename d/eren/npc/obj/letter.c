inherit ITEM;

void create()
{
        set_name("急信", ({ "letter"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","石雁道兄，\n"
"\n"
"	华山一别，忽忽又已数载。\n"
"        飞骑传书，只为小徒之事。数日前此徒勾结寺外歹人，杀伤我护寺\n"
"武僧，趁夜于木人巷后门潜出少林，更以下山弟子之名游荡江湖。本寺确有\n"
"下山一说，但唯悟禅理，敬佛祖之僧人方能为之，更需得其业师所允。此徒\n"
"不尊师命，私闯禁地，杀伤同门，大悖我佛之理。\n"
"	据闻此徒已入武当门下，望慎察。\n"
"	念其入寺多年，勤勉有加，若能迷途知返，可命其速归师门，面壁\n"
"悔过，以往之事一概不究。若执迷不悟，或逾时不归，当将其劣迹昭告同门，\n"
"通晓武林，不得再以下山弟子自称。\n"
"\n"
"						心湖\n"
"\n"
"\n");
                set("value", 1);
        }
}
