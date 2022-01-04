inherit	TUTOR;

void create()
{
	set_name("幻世道法", ({ "spellsbook" }));    
	set_weight(600);
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long",	"一本手抄的薄薄纸书，字迹凌乱不堪。你凝神看去，\n"
"上面所记载的却是极深的武功（learn xxx from spellsbook with 潜能点数）\n");
		set("no_transfer", 1);
		set("teaching", "spells");
		set("teaching_limit", 100);
		set("teaching_require", 40);
		set("value",1000);
		set("material", "paper");
 	}
}