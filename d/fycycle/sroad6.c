inherit ROOM;
void create()
{
        set("short", "城东小路");
        set("long","北边就是高大的风云城，一条宽阔的大道，穿过连绵不绝的群山，一直通向东\n"
"海边。马路上人来人往，热闹非凡。都是些江湖儿女，面带严肃，赶去为紫衣侯大\n"
"战白衣人加油去的。\n"
""
        );
        set("exits", ([ /* sizeof() == 4 */
 //"east" : "/u/hangzhou/road0",
	  "north":	__DIR__"fyeast",
	  "southwest": __DIR__"sroad5",
]));
        set("outdoors", "fengyun");
	set("coor/x",320);
	set("coor/y",-80);
	set("coor/z",0);
	setup();     

}

