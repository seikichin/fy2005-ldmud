// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "正厅");
        set("long","大宅朱漆大门，门上茶杯大小的铜钉闪闪 发光，门顶匾额写着“福威镖局”\n"
"四个金漆大字，下面横书“总号”两个小字。进门处两排长凳，分坐着八名劲\n"
"装结束的汉子，个个腰板笔挺，显出一股英悍之气。\n"
""
        );
	set("exits",([
  		"north" : __DIR__"fuweibiaoju1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}