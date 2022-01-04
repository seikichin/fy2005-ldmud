
inherit ROOM;

void create()
{
        set("short", "天涯路");
        set("long","万里荒寒，连残阳都似已因寂寞而变了颜色，变成一种空虚而苍凉的灰白色。\n"
"漠漠黄沙，无边无际。似乎永远也走不到头，一眼望去，天连着黄沙，黄沙连着\n"
"天；人，也已在天涯。  \n"
""
        );
        set("exits", ([ 
		"southeast" : __DIR__"mfoot",
  		"northwest" : __DIR__"skyroad2",
	]));
        set("outdoors", "quicksand");

	set("coor/x",-1120);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}
