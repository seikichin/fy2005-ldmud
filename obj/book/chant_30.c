
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
    set_name("石碑", ({ "石碑","shibei","bei"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "块");
		set("long",
"孔子门生问曰：暮春者，春服，既成，冠者六七人，浴乎沂，风乎舞雩，咏而归。\n"
"孔子听罢道：吾与点也。此台由此得名。\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
	        set("skill", ([
                        "name":        "chanting",
                        "exp_required": 0,
                        "sen_cost":     5,
                        "difficulty":   10,
                        "max_skill":    29,
                        "literate":	"literate",
                        "liter_level":	30,
                ]) );
	}
}
