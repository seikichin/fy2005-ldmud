inherit ROOM;

void create()
{
	set("short", "翠竹园");
	
        set("long","“有竹无肉轩”四周就是翠竹园，这里种满了竹，每到风清月白的夏夜，富贵\n"
"山庄的历代主人们便会来此，一把竹椅，一壶清茶，听那海浪般的竹涛声，可惜王\n"
"动很久已经没这个兴致了，倒是会时常和他的兄弟们砍竹卖钱换酒，年复一年，翠\n"
"竹园中的竹子也越来越少，\n");

	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"south":__DIR__"wuzhuxuan",
	]) );
        set("objects" , ([
        	__DIR__"obj/bspear" : 2,
        ]));

	set("coor/x",-10);
	set("coor/y",220);
	set("coor/z",80);
	setup();
}

void reset(){
        object item;
        int i;
        ::reset();
      
	if(!present("bamboo spear", this_object())){
                for (i=1; i<=2 ; i++) {
                	item = clone_object(__DIR__"obj/bspear");
	                if(objectp(item)){
                        item->move(this_object());
                	}
	        }
        }
        return;
}          