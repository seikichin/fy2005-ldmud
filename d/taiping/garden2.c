inherit ROOM;
void create()
{
        set("short", "花圃");
        set("long","西风满院，败叶满径。院子里栽有几棵芭蕉。“深怕数秋更，况复秋声彻夜惊。\n"
"第一雁声听不得，才听，又是秋虫第一声。凄绝梦回程，冷雨愁花伴小庭。遥想故\n"
"人千里外，关情，一样疏窗一样灯”，冷萧萧，笆蕉风碎，你的心亦似被摇曳在风\n"
"中的芭蕉叶割碎了。\n"
""
        );
        set("exits", ([ 
		"north" : __DIR__"pavilion",
		"east": __DIR__"corridor4",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-100);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
