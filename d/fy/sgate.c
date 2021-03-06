#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"风云南城门"NOR);
    set("long","风云南大门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳头般大小的柳钉。\n"
"门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧贴满了悬赏捉拿之类的官府\n"
"通谍。门洞西侧则是一条上城墙的窄梯。（清官匪需交风兵或云卒１０两黄金）\n"
);
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"swind4",
	"up"   : AREA_FYWALL"supgate",
	"south" : "/d/fycycle/fysouth",
      ]));
    set("objects", ([
	__DIR__"npc/wind_soldier" : 2,
	__DIR__"npc/cloud_soldier": 2, 
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-300);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}

int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    if( userp(me) && ob=present("garrison", this_object()))
    {
	if( dir == "north" && !random(10) )	{
	    inv = all_inventory(me);
	    for(i=0; i<sizeof(inv); i++)	{
		if(({int})(inv[i]->query("weapon_prop")) && ({int})(inv[i]->query("equipped")))
		    return notify_fail(ob->name()+"向你喝道：不可手持兵器入风云城！\n");	
	    }
	}

	if ( dir == "north" && me->is_naked())  {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"皱着眉头说：小孩子光着屁股跑来跑去，像什么样子！\n\n");
			else
				return notify_fail(ob->name()+"向你喝道：赤身裸体招摇过市，成何体统！！\n");
		}

	if( dir == "up")       {
	    inv = all_inventory(me);
	    for(i=0; i<sizeof(inv); i++)
	    {
		if((({string})(inv[i]->name()) == "风云战甲") && ({int})(inv[i]->query("equipped")))
		    return 1;
	    }
	    return notify_fail(ob->name()+"向你喝道：闲杂人等不可上登护城墙！\n");
	}
    }

	return 1;

}
