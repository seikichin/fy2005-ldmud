#include <ansi.h>

inherit ROOM;
string *names=({
  __DIR__"maze7",
  __DIR__"maze3",
  __DIR__"flowerroad",
  __DIR__"maze1",
} );
void create()
{
    set("short", BLU"花海"NOR);
    set("long","海风习习，微微有些咸味之中夹着扑鼻花香，远远望去，蜿蜒曲折的小径上郁郁\n"
"葱葱，一团绿、一团红、一团黄、一团紫，端的是繁花似锦，落英缤纷。白云岛因天\n"
"地之宜，终年暖湿，树木长绿，花草繁茂，而岛上可爱的少女更是健康而可爱，纤手\n"
"轻扬。花香满径，人比花香。\n"
);
    set("outdoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-50);
    set("coor/z",10);
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

