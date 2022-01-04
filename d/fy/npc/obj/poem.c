// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "风云赞歌", ({ "poem song","poem"  }) );
    set("unit", "首");
    set("long","\n"
"		是非成败转头空，\n"
"                	风云依旧在，\n"
"                		几度血光红。\n"
"\n"
"\n");
    set_weight(1);
    ::init_item();
}
