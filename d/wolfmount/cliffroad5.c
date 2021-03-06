inherit ROOM;

void create()
{
	set("short", "悬崖栈道");

	set("long","一条依傍着悬崖峭壁的栈道，弯弯曲曲不知通向何方。抬头往上看去，云雾缭\n"
"绕，山气渐浓。身下则是万丈沟壑，深不见底。栈道年久失修，木制护栏断的断，\n"
"折的折，一不小心就不免坠入下面的无底深渊。\n");

	set("type","road");
	set("exits",([
        "northwest":__DIR__"cliffroad1",
        "southeast":__DIR__"cliffroad2",
	]) );
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",-30);
       set("outdoors", "wolfmount");

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	object room;

	if (me->query("timer/insurance") + 259200 > time())
		return 1;

	if( userp(me))
	{
        switch(random(15))
		{
			case 0:
				message_vision("$N脚下一滑，身子在悬崖栈道上晃了晃．．\n",me);
				return notify_fail("还好，没掉下去！\n");
				break;
			case 1:
				inv = all_inventory(me);
				if(sizeof(inv)>=1)	
				{
					ob = inv[random(sizeof(inv))];
                    if (ob->query("no_drop") || ob->query("owner")
                    	|| ob->query_autoload() ) break;
					message_vision(ob->name()+"从$N身上滑了出来，落入万丈深渊．\n",me);
					destruct(ob);
				}
				return 1;
				break;
			case 2:
				message_vision("$N在悬崖栈道上前仰后合地晃着......\n",me);
                if ( me->query("kar") <= 22 )
				{
					message_vision("伴随着一声杀猪般的凄厉惨嚎，$N失足落下悬崖......\n",me);
					me->unconcious();
					room = find_object(__DIR__"undercliff");
					if(!objectp(room)) room = load_object(__DIR__"undercliff");
					me->move(room);
					return 0;
				}
				else
				{
					message_vision("$N连忙坐到地上，还好，终于安全了......\n",me);
					return 1;
				}
				
				break;
			default:
				return 1;
				break;
		}
		return 1;
	}
	else
	return 1;
}
