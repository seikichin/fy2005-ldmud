#include <room.h>  
inherit ROOM;
void create()
{
  set("short","石道");
  set("long","\n"
"这只是一条长数尺的石道，石道尽头是一片池泊，但闻水声潺潺，隐约传来。\n"
);
  	set("exits/center" ,__DIR__"shishi");
  	set("exits/north"  ,__DIR__"outboat");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
 }
