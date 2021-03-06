#include <ansi.h>
inherit __DIR__"cemetery";

string *names=({
	__DIR__"cemetery10",
	__DIR__"cemetery7",
	__DIR__"cemetery1",
	__DIR__"cemetery6",
} );


void create()
{
        set("short", "坟场");
        set("long","天色阴森，风也更冷，远处高低起伏，关帝庙的后面竟是一片无边无际的荒坟。\n"
"虽然是白天，荒坟间仍然有雾，坟中也仍然有自骨死人。阴沉的天气，凄迷的冷雾。\n"
"昏暗的天空中，一只鸟影正飞向西方，带着铃声飞向西方。西方有极乐世界。西方\n"
"也有穷山，恶水，旷野，荒坟。\n"
""
        );
        set("outdoors", "biancheng");
        set("coor/x",-100);
	set("coor/y",20);
	set("coor/z",0);
	set("no_lu_letter",1);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}
